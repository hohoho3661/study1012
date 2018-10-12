#pragma once

#pragma warning(disable:4996) // stpringf�� unsafe�ϴٴ� ������ ����.
// Windows ��� ���� :
#include <Windows.h>


// C ��Ÿ�� ��� �����Դϴ�.

#include <assert.h>

#include <stdlib.h>
#include <malloc.h>
#include <memory.h>

#include <iostream>		// cout, cin, endl,,,,,
#include <functional>   // c++������ �Լ������� ������,,, �߰�.

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
#include <math.h> // �ﰢ�Լ�.



// ����� ���� ���
#include "commonMacroFuntion.h"

#include "Util.h"
#include "CollisionFunction.h"

#include "RandomFunction.h"


#include "Image.h"
#include "Camera.h"

#include "GameNode.h"

// �ִϸ��̼�
#include "Animation.h"

//
#include "CustomDefine.h"
#include "MacroDefine.h"


// �Ŵ���
#include "KeyManager.h"
#include "ImageManager.h"
#include "TimeManager.h"
#include "EffectManager.h"
#include "SceneManager.h"
#include "SoundManager.h"

#include "AniManager.h"

#include "TextData.h" //