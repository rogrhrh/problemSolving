# chapter 2

> ### C++ 프로그램
	c++ 프로그램은 함수라고 하는 하나 이상의 모듈로 이루어진다.
	main() 함수부터 실행이 시작된다 따라서 main함수는 반드시 하나 존재해야 한다.

> ### 함수

	함수는 함수 머리와 함수 몸체로 이루어진다
	함수머리 : 리턴하는 데이터형, 매개변수로 받는 정보
	함수몸체 : 함수의 식을 이루는 중괄호로 둘러쌓인 구문들

> ### C++ 구문 유형

	선언구문 : 변수의 이름과 데이터형 선언
	대입구문 : 대입연산자를 사용한 값 대입
	메시지구문 : 객체에 메시지를 전달하여 활동을 시작
	함수호출 : 함수동작, 피호출 함수 종료시 다음 구문으로 복귀한다.
	함수원형 : 매개변수의 개수, 매개변수의 데이터형, 함수의 리턴형 선언
	return 구문 : 피호출 함수가 리턴하는 값을 호출 함수에 전달
	
> ### 클래스 

	사용자가 정의하는 데이터 형식, 정보를 어떤식으로 표현하고 무슨 동작을 하는지 정의
	객체는 클래스의 속성을 사용하여 실제로 생성하는 구체물

	
> ### 입출력

	cout, cin을 사용한다. iostream 헤더에 저장
	삽입연산자(<<) 은 ostream 추출연산자(>>) istream 에 정의되어 있다.
	cin, cout 클래스는 프로그램의 문맥에 따라 한 형식을 자동으로 다른 형식으로 변환 할 수 있다.

> ### 라이브러리 함수

	라이브러리 함수를 사용하려면 함수 원형을 제공하는 헤더 파일을 프로그램에 포함시켜야 한다.