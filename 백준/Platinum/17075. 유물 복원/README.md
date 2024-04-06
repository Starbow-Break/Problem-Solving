# [Platinum V] 유물 복원 - 17075 

[문제 링크](https://www.acmicpc.net/problem/17075) 

### 성능 요약

메모리: 26464 KB, 시간: 16 ms

### 분류

다이나믹 프로그래밍, 배낭 문제, 수학

### 제출 일자

2024년 4월 7일 00:40:33

### 문제 설명

<p>서울 Y모 대학에서 끊임없이 소음과 분진을 발생시키며 공사를 진행하던 중, 고대 유물로 추정되는 석판 하나가 발굴되었다. 이 석판은 <em>N</em>개의 행과 <em>M</em>개의 열로 나누어진 격자 형태로, 각 칸은 텅 빈 칸이거나 사람 한 명이 그려진 칸이었다. 석판은 아쉽게도 온전한 형태로 발굴되지는 않았으며, 칸들 중에는 일부가 부서져 있어 내용을 식별할 수 없는 칸도 있었다.</p>

<p>그 후 얼마 지나지 않아, 관련 자료를 통해 이 석판의 규칙을 알 수 있게 되었다. 이 석판에서 가능한 모든 부분 직사각형에 대해 내부의 사람 수를 구하고, 그 수들을 모두 더해서 얻는 값이 <em>K</em>의 배수여야 한다는 것이다. 0은 모든 수의 배수가 될 수 있다.</p>

<p>예를 들어, 2 × 2 크기의 아래 석판을 보자.</p>

<p style="text-align: center;"><img alt="" src="https://upload.acmicpc.net/2b85c7f5-9374-401e-b165-c241384bb758/-/preview/" style="height: 252px; width: 250px;"></p>

<p>위 석판에는 아래와 같이 9개의 부분 직사각형이 있다.</p>

<p style="text-align: center;"><img alt="" src="https://upload.acmicpc.net/876880fe-94ac-4e3a-8247-5bd50a446957/-/preview/" style="height: 151px; width: 150px;"><img alt="" src="https://upload.acmicpc.net/ad277de5-15d1-41a4-b548-8ea5ab5d327d/-/preview/" style="height: 151px; width: 150px;"><img alt="" src="https://upload.acmicpc.net/824f9d3f-b6f4-4b6b-a0db-f4ed2e0787e4/-/preview/" style="height: 151px; width: 150px;"><img alt="" src="https://upload.acmicpc.net/7deb3b54-3ef6-4f9f-a98c-dbf007313cab/-/preview/" style="height: 151px; width: 150px;"><img alt="" src="https://upload.acmicpc.net/8154a029-55ed-47b7-855e-99fdf791b9ab/-/preview/" style="height: 151px; width: 150px;"><img alt="" src="https://upload.acmicpc.net/019957ae-3bd3-4494-a6c4-70fd6ebc6438/-/preview/" style="height: 151px; width: 150px;"></p>

<p style="text-align: center;"><img alt="" src="https://upload.acmicpc.net/8a9a7f71-61cc-4110-92b7-aeb79bbf7429/-/preview/" style="height: 151px; width: 150px;"><img alt="" src="https://upload.acmicpc.net/94cc0675-2390-49cf-9428-c5a622635a69/-/preview/" style="height: 151px; width: 150px;"><img alt="" src="https://upload.acmicpc.net/334dbb54-269a-4038-82fd-b5a586814632/-/preview/" style="height: 151px; width: 150px;"></p>

<p>각 부분 직사각형 내부의 합은 1, 0, 0, 1, 1, 1, 1, 1, 2가 되고, 이들의 총합은 8이 된다.</p>

<p>학교 측은 얻은 정보를 토대로 석판을 가능한 형태 중 하나로 복원하기 위해 연세대학교 컴퓨터과학과에 복원작업을 의뢰하었고, 자연스럽게 이 과제는 2019 교내 대회의 문제로 출제되게 되었다. 당신은 석판의 형태와 <em>K</em>를 입력으로 받아 석판의 복원이 가능한지 알아보고, 가능할 경우 조건을 만족하는 석판 하나를 복원해야 한다.</p>

### 입력 

 <p>첫째 줄에 석판의 행의 수 <em>N</em>과 열의 수 <em>M</em>, 문제에 제시된 <em>K</em>가 주어진다. (1 ≤ <em>N, M </em>≤ 50, 2 ≤ <em>K</em> ≤ 2500)</p>

<p>둘째 줄부터 <em>N+1</em>번째 줄까지, 각 줄에 <em>M</em>개의 정수 <em>a<sub>i,j</sub></em>가 공백으로 구분되어 주어진다. (<em>a<sub>i,j</sub></em> ∈ { -1, 0, 1})</p>

<p><em>a<sub>i,j</sub></em>  = -1일 경우 석판의 <em>i</em>번째 행 <em>j</em>번째 열이 부서져 있음을, <em>a<sub>i,j</sub></em>  = 0 일 경우 해당 칸이 비어 있음을, <em>a<sub>i,j</sub></em>  = 1일 경우 해당 칸에 사람 한 명이 그려져 있음을 의미한다.</p>

### 출력 

 <p>복원이 가능할 경우 첫 줄에 1을, 불가능할 경우 -1을 출력한다.</p>

<p>만약 첫 줄에 1을 출력했다면, 이어 <em>N</em>개의 줄에 <em>M</em>개의 정수로 행렬에 존재하는 모든 -1을 0 또는 1로 대체하여 문제의 조건에 맞게 복원한 석판 하나를 출력한다. 입력에서 -1이 아니었던 모든 칸은 입력과 동일해야 하며, -1인 모든 칸은 0 또는 1 중 하나로 복원되어야 한다.</p>

<p>조건을 만족하는 석판이 여러 가지라면 아무 것이나 하나만 출력한다.</p>

