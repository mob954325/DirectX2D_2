## 프로젝트 개요
해당 프로젝트는 DirectX11 2D Api로 구성되어 있습니다.
유니티 엔진구조를 참조하여 컴포넌트 구조를 간단하게 만들었습니다.

### 주요 기능
1. Script 컴포넌트와 Render 컴포넌트를 중심으로 컴포넌트를 상속받아서 게임 개발에 추가할 수 있습니다.
2. 사용자는 MonoBehavior에 내용을 정의하고 해당 컴포넌트를 게임 오브젝트에 addComponent로 연결하여 게임 업데이트 루프에 추가할 수 있습니다.
3. RenderComponent는 D2DRenderManager를 참조해 DirectX2D 관련 코드를 사용하여 선, 이미지 출력, 텍스트 출력을 할 수 있습니다.

[사용한 프로젝트 : 검을 그리라 공방록](https://github.com/NaturalDisaster7/2Q_AttackDefenceLog?tab=readme-ov-file)

### 게임 루프
<img width="2951" height="1025" alt="GameLoop" src="https://github.com/user-attachments/assets/a489f71b-2a50-4257-a541-143b6d4d9a91" />

### 게임 리소스 출력
<img width="1892" height="631" alt="Resource" src="https://github.com/user-attachments/assets/0d18d688-81fd-41fa-b8e0-0eed8f86b5b6" />

### 사용자 컴포넌트 구조
<img width="1642" height="481" alt="UserComponent" src="https://github.com/user-attachments/assets/9b647ee1-4f56-4817-b686-7bc6da0958a1" />

### 오브젝트 구조
<img width="2391" height="1561" alt="GameObjectLoop" src="https://github.com/user-attachments/assets/e938dd69-79e4-4a33-9f69-b1ce0750bf42" />
