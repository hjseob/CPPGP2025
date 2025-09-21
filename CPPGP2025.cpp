// CPPGP2025.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include "ZVector3.h"
#include "ZMatrix.h"

int main()
{

	ZVector3 v1(1, 2, 3);
	std::cout << v1 << std::endl;

	ZVector3 v2(4, -5, 6);
	std::cout << v2.Cross(v1) << std::endl;

	std::cout << ZVector3::Dot(v1, v2) << std::endl;
	std::cout << v1.radBetween(v1, v2) << std::endl; // Todo: radBetween을 스태틱으로 하던지 파라미터를 대상 벡터 1개만 받도록 수정!
	std::cout << v1.degBetween(v1, v2) << std::endl;
	
	// Matrix test
	//SRT
	ZVector3 localPoint(1.0, 1.0, 1.0);
	std::cout << "Local Space Point : " << localPoint << std::endl;

	// scale 모든 축으로 2배 확대
	//localPoint.Scale() // 해도 되지만 SRT 연산을 모두 해야 하는 경우 매트릭스로 전체를 설계해서 한번에 하자!
	ZMatrix matScale = ZMatrix::CreateScale(2.0, 2.0, 2.0);

	// rotation : y축 90도 회전 
	// 왼손좌표계이고 시계방향으로 회전하겠다 라는것까지 인지하고 머릿속으로 계산해서 결과값이 맞는지 확인하고 사용하는 습관들이기!!

	const double PI = 3.1415926535897932;
	ZMatrix matRotation = ZMatrix::CreateRotationY(PI / 2.0); // 90도
	
	// translation : 월드 공간의 (5,6,7) 위치로 이동
	ZMatrix matTranslation = ZMatrix::CreateTranslation(5.0, 6.0, 7.0);

	// 변환을 순차적으로 적용
	// 스케일
	ZVector3 pointAfterScale = localPoint.Transform(matScale);
	std::cout << pointAfterScale << std::endl;
	// 회전
	ZVector3 pointAfterRotation = pointAfterScale.Transform(matRotation);
	std::cout << pointAfterRotation << std::endl;
	// 이동
	ZVector3 finalWorldPoint = pointAfterRotation.Transform(matTranslation);
	std::cout << finalWorldPoint << std::endl;


	// 한번에 연산 하기!
	ZMatrix worldMatrix = matScale * matRotation * matTranslation;
	ZVector3 finalWorldPointByMatrix = localPoint.Transform(worldMatrix);
	std::cout << finalWorldPointByMatrix << std::endl;
}