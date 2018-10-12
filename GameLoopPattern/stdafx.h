#pragma once

#pragma warning(disable:4996) // stpringf가 unsafe하다는 오류를 막음.
// Windows 헤더 파일 :
#include <Windows.h>


// C 런타임 헤더 파일입니다.

#include <assert.h>

#include <stdlib.h>
#include <malloc.h>
#include <memory.h>

#include <iostream>		// cout, cin, endl,,,,,
#include <functional>   // c++에서의 함수포인터 설명중,,, 추가.

#include <vector>
#include <list>
#include <map>
#include <string>

using std::vector;
using std::list;
using std::map;
using std::string;


#include <tchar.h>
#include <stdio.h>
#include <math.h> // 삼각함수.



// 사용자 정의 헤더
#include "commonMacroFuntion.h"

#include "Util.h"
#include "CollisionFunction.h"

#include "RandomFunction.h"


#include "Image.h"
#include "Camera.h"

#include "GameNode.h"

// 애니메이션
#include "Animation.h"

//
#include "CustomDefine.h"
#include "MacroDefine.h"


// 매니저
#include "KeyManager.h"
#include "ImageManager.h"
#include "TimeManager.h"
#include "EffectManager.h"
#include "SceneManager.h"
#include "SoundManager.h"

#include "AniManager.h"

#include "TextData.h" //