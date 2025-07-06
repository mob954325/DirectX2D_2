#pragma once
#include "Components/Logic/ScriptComponent.h"
#include "Datas/AnimationControllerDatas.h"
#include "unordered_map"
#include "vector"
// 1. 파라미터 타입
// 2. 각 타입별 컨테이너
// 3. Update
// 3.1. 컨디션 체크

class IStateBehaviorBase
{
public:
	virtual void OnStateEnter() = 0;
	virtual void OnStateUpdate() = 0;
	virtual void OnStateExit() = 0;
};

class FSMInstance : public ScriptComponent
{
private:
	AnimatorController* controller{};
	int currentStateIndex = -1;
	int prevStateIndex = -1;

	float elapsedTime = 0.0f;

	// 상태 
	std::vector<IStateBehaviorBase*> stateBehavitors;

	// 파라미터 컨테이너
	std::unordered_map<std::string, int> intParams;
	std::unordered_map<std::string, float> floatParams;
	std::unordered_map<std::string, bool> boolParams;
	std::unordered_map<std::string, bool> triggerParams;

	void RegisterIntParameters();
	void RegisterFloatParameters();
	void RegisterBoolParameters();
	void RegisterTriggerParameters();

	void ChangeState(const std::string& name);

	void ResetTrigger(const std::string& name);

	void StartStateBehavior(int index);
	void UpdateStateBehavior(int index);
	void ExitStateBehavior(int index);

public:
	// eventCycle
	void OnStart() override;
	void OnEnd() override;
	void Update() override;
	bool EvaluateConditions(std::vector<Condition>& conditions);

	// init
	void SetAnimationController(AnimatorController& ac);
	void SetStateBehavior(std::string stateName, IStateBehaviorBase* state);

	// Param getter/setter
	int GetInt(const std::string& paramName);
	void SetInt(const std::string& paramName, int value);

	bool GetBool(const std::string& paramName);
	void SetBool(const std::string& paramName, bool value);

	float GetFloat(const std::string& paramName);
	void SetFloat(const std::string& paramName, float value);

	void SetTrigger(const std::string& paramName);
	bool GetTrigger(const std::string& paramName);

	// flag
	bool IsParameterChanged(Condition& condition);
};