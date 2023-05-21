# 엽기떡볶이 메뉴판
![image](https://github.com/leedohyung28/ILoveMovies/assets/91038179/89e834b5-5256-4964-8569-24c1cf0c7454)

엽기떡볶이 메뉴(2021년 6월 기준) 를 선택하고 삭제할 수 있게 간단한 GUI가 구현된 프로그램

---

### 💡 설계에서 중요한 점
> 1. C++에서 Console 창을 통한 간단한 GUI 구현
> 2. 토핑과 세트 메뉴 등 여러 가지 메뉴를 손쉽게 추가하고 빼기 위한 프로그램 구현

---

### 🎓 Using Tools

#### Platform 🏬
<img src="https://img.shields.io/badge/Eclipse-2C2255?style=for-the-badge&logo=Eclipse IDE&logoColor=white">

#### Languages 🚩
<img src="https://img.shields.io/badge/C++-00599C?style=for-the-badge&logo=C++&logoColor=white">

---

### 엽기떡볶이 메뉴판

---

### 헤더 파일 및 CPP 구조
![image](https://github.com/leedohyung28/ILoveMovies/assets/91038179/d005cba8-55ee-40df-87ec-c5796e91f6ac)

---

### 코드 구성

##### 헤더 파일(yupkituk.h)
|함수|이름|정의된 곳|기능|
|:---:|:---:|:---:|:---:|
|void|mainscreen|X|중심 화면|
|void|setmenu|X|세트 메뉴 선택|
|void|setmenu_side|X|세트메뉴 중 사이트|
|void|addcart|Cart|장바구니에 추가|
|void|erasecart|Cart|장바구니에서 제거|
|void|deleteoncart|Cart|제거에 관한 함수|
|void|resultshow|Cart|최종결과 출력|
|void|spicyselect|Maindish|맵기 정도 선택|
|void|mainmenu|Maindish|메인 메뉴 선택|
|void|setmenu_main|Maindish|세트 메뉴 중 메인|
|void|setmenu_chicken|Maindish|세트 메뉴 중 닭발|
|void|show_main|Maindish|메인 메뉴 보여주기|
|void|toppingmenu|Topping|토핑 메뉴 선택|
|void|show_top|Topping|토핑 메뉴 보여주기|


##### 특이한 사용
> 1. std::cin.fail : 숫자가 아닌 다른 것을 입력할 때 cin.fail로 오류 여부 체크
> 2. goto 문 : 잘못 입력 시 원래 선택으로 되돌아 가는 경우가 있다. 이 때 goto문을 자주 사용 하지만, goto문을 사용하는 것을 지양한다.
> 3. append : 장바구니에 입력된 문자열을 수정 (ex. 맵기 -> 음식 뒤에 append, 세트 표시 -> 음식 뒤에 append)

##### 정보의 표현 및 처리
> 1. 메뉴 정보의 표현 및 처리 : Menu 클래스로 메뉴 정보 처리
> 2. 주문 정보의 표현 및 처리 : Cart 클래스로 처리
> 3. 입력 표현 및 처리 : 프로그램 내의 모든 선택 결과를 사용자에게 보여줌 (메시지 출력)
