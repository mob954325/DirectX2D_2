#include "JsonUtil.h"
#include "framework.h"
#include <fstream>
#include <stdexcept>
#include "json.hpp"

#include <locale>
#include <codecvt>

using json = nlohmann::json;

/// <summary>
/// String을 Wsting으로 변환하는 함수
/// </summary>
std::wstring StringToWstring(const std::string& str)
{
	std::wstring_convert<std::codecvt_utf8<wchar_t>> converter;
	return converter.from_bytes(str);
}

std::string WstringToString(const std::wstring& str)
{
	std::wstring_convert<std::codecvt_utf8<wchar_t>> converter;
	return converter.to_bytes(str);
}

// https://json.nlohmann.me/api/adl_serializer/from_json/
// 사용자 정의 자료형을 .get하려면 밑의 함수 처럼 구현해야함
void from_json(const nlohmann::json& j, Sprite& sprite) {

	std::string temp;
	j.at("name").get_to(temp);
	sprite.name = StringToWstring(temp);
	j.at("x").get_to(sprite.x);
	j.at("y").get_to(sprite.y);
	j.at("width").get_to(sprite.width);
	j.at("height").get_to(sprite.height);
	j.at("pivotX").get_to(sprite.pivotX);
	j.at("pivotY").get_to(sprite.pivotY);
}

void JsonUtil::LoadSpriteSheet(const std::wstring& filePath, SpriteSheet& spriteSheet)
{
	std::ifstream inFile(filePath);
	if (inFile.is_open())
	{
		json j;
		inFile >> j;
		inFile.close();

		// JSON 데이터 추출
		spriteSheet.texture = StringToWstring(j["texture"]);
		spriteSheet.textureWidth = j["textureWidth"];
		spriteSheet.textureHeight =j["textureHeight"];
		spriteSheet.sprites = j["sprites"].get<std::vector<Sprite>>();

		// 스프라이트 이름으로 인덱스 맵 생성
		for (int i = 0; i < spriteSheet.sprites.size(); i++)
		{
			spriteSheet.spriteIndexMap[spriteSheet.sprites[i].name] = i;
		}
	}
	else
	{
		throw std::runtime_error("Sprite not found in sprite sheet: " + WstringToString(filePath));
	}
}

void from_json(const nlohmann::json& j, FrameInfo& frameinfo)
{
	std::string temp;
	j.at("sprite").get_to(temp);
	frameinfo.sprite = StringToWstring(temp);
	j.at("time").get_to(frameinfo.duration);
}

//void from_json(const nlohmann::json& j, EventInfo& eventinfo) 
//{
//	j.at("function").get_to(eventinfo.function);
//	j.at("parameter").get_to(eventinfo.parameter);
//	j.at("time").get_to(eventinfo.time);
//}

void JsonUtil::LoadAnimationClip(const std::wstring& filePath, AnimationClip& clip, const SpriteSheet& spriteSheet)
{
	std::ifstream inFile(filePath);
	if (inFile.is_open()) {
		json j;
		inFile >> j;
		inFile.close();
		// JSON 객체에서 데이터 추출
		clip.clipName = StringToWstring(j["clipName"]);
		clip.texturePath = StringToWstring(j["texturePath"]);
		clip.loop = j["loop"];
		clip.duration = j["duration"];
		clip.frames = j["frames"].get<std::vector<FrameInfo>>(); // j -> std:sting ?
		//clip.events = j["events"].get<std::vector<EventInfo>>();

		// 프레임의 sprite 이름을 인덱스로 변환
		for (auto& frameIndex : clip.frames) {
			auto it = spriteSheet.spriteIndexMap.find(frameIndex.sprite);
			if (it != spriteSheet.spriteIndexMap.end()) {
				frameIndex.spriteSheetIndex = it->second; // sprite 이름으로 인덱스 찾기
			}
			else {
				throw std::runtime_error("Sprite not found in sprite sheet: " + WstringToString(frameIndex.sprite));
			}
		}
	}
	else {
		throw std::runtime_error("Failed to open animation clip file: " + WstringToString(filePath));
	}
}
