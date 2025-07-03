#include "AnimationControllerLoader.h"
#include "Utils/StringConvert.h"

#include <fstream>
#include <stdexcept>
#include "External/json.hpp"

using json = nlohmann::json;

#pragma region animator json 파싱 함수
// Parameter
void from_json(const nlohmann::json& in, Parameter& out)
{
	in.at("name").get_to(out.name);
	in.at("type").get_to(out.type);
	in.at("defaultFloat").get_to(out.defaultFloat);
	in.at("defaultInt").get_to(out.defaultInt);
	in.at("defaultBool").get_to(out.defaultBool);
}

// Condition
void from_json(const nlohmann::json& in, Condition& out)
{
	in.at("parameter").get_to(out.parameter);
	in.at("mode").get_to(out.mode);
	in.at("threshold").get_to(out.threshold);
}

// Transition
void from_json(const nlohmann::json& in, Transition& out)
{
	in.at("fromState").get_to(out.fromState);
	in.at("toState").get_to(out.toState);

	if (in.contains("conditions")) {
		out.conditions = in.at("conditions").get<std::vector<Condition>>();
	}
	in.at("exitTime").get_to(out.exitTime);
	in.at("hasExitTime").get_to(out.hasExitTime);
}

// AnyStateTransition
void from_json(const nlohmann::json& in, AnyStateTransition& out)
{
	in.at("toState").get_to(out.toState);
	if (in.contains("conditions")) {
		out.conditions = in.at("conditions").get<std::vector<Condition>>();
	}
}

// State
void from_json(const nlohmann::json& in, State& out)
{
	in.at("name").get_to(out.name);
	in.at("motionName").get_to(out.motionName);
	in.at("clipLength").get_to(out.clipLength);
	in.at("loop").get_to(out.loop);
	if (in.contains("transitions")) {
		out.transitions = in.at("transitions").get<std::vector<Transition>>();
	}
}

// AnimatorController
void from_json(const nlohmann::json& in, AnimatorController& out)
{
	in.at("controllerName").get_to(out.controllerName);
	out.parameters = in.at("parameters").get<std::vector<Parameter>>();

	// 첫번째 Layer의 상태머신만 처리
	in.at("defaultState").get_to(out.defaultState);
	if (in.contains("states"))
	{
		out.states = in.at("states").get<std::vector<State>>();
	}

	if (in.contains("anyStateTransitions"))
	{
		out.anyStateTransitions = in.at("anyStateTransitions").get<std::vector<AnyStateTransition>>();
	}
}
#pragma endregion

void AnimationControllerLoader::LoadAnimatorController(const std::wstring& filePath, AnimatorController& out)
{
	std::ifstream inFile(filePath);
	if (inFile.is_open())
	{
		json in;
		inFile >> in;
		inFile.close();
		// JSON 객체에서 데이터 추출
		out.controllerName = in["controllerName"];
		out.parameters = in["parameters"].get<std::vector<Parameter>>();
		out.defaultState = in["defaultState"];

		if (in.contains("states")) 
		{
			out.states = in["states"].get<std::vector<State>>(); // 
		}

		for (int i = 0; i < out.states.size(); ++i) 
		{
			out.stateNameToIndex[out.states[i].name] = i;
			out.states[i].index = i; // 상태 인덱스 설정
		}

		if (in.contains("anyStateTransitions")) 
		{
			out.anyStateTransitions = in["anyStateTransitions"].get<std::vector<AnyStateTransition>>();
		}
	}
	else 
	{
		throw std::runtime_error("Failed to open animation clip file: " + StringConvert::WstringToString(filePath));
	}
}