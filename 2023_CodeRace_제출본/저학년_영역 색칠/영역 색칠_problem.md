### 영역 색칠
---
**시간 제한 1초 메모리 제한 512MB** 

격자선을 따라 그려진 N X M 크기의 그림을 똑같이 따라 그리려고 한다. 그림은 두 가지 색으로 이루어져 있다.<br>
그림 도구인 붓은 가로 방향만 칠할 수 있는 가로붓만 존재한다. 붓의 두께는 1이다. 붓질 한 번에 칠할 수 있는 길이의 제한은 없고 덧칠이 가능하다.<br>
그림을 똑같이 그리는 데에 최소 몇 번의 붓질이 필요한지 구해보자.

---

### 입력
```
첫째 줄에는 그림의 크기를 나타내는 두 정수 N, M이 주어진다. N은 그림의 세로 길이, M은 그림의 가로 길이를 나타낸다.
(2 ≤ N, M ≤ 100)
둘째 줄부터 N개의 줄에 M개의 숫자로 그림이 주어진다. 0은 색이 칠해지지 않은 공간, 1과 2는 각 색이 칠해진 공간을 의미한다. 
```
### 출력
```
그림을 똑같이 그리는데 필요한 붓질의 최소 횟수를 출력한다.
```

### 예제 입력1
```
2 2
2 1
0 0
```

### 예제 출력1
```
2
```

### 예제 입력2
```
4 4
1 0 0 1
1 1 2 2
0 0 1 2
0 1 1 1
```

### 예제 출력2
```
7
```