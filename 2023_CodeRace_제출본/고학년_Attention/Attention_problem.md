### Attention
---
**시간 제한 2초 메모리 제한 512MB**  
```
You and me
내 맘이 보이지
한참을 쳐다봐
가까이 다가가
You see
You see, ey ey ey ey
```

산지니는 새내기를 좋아한다. <br>
그래서 산지니는 새내기가 쿠키를 좋아한다고 알고 새내기가 좋아하는 맛의 쿠키를 선물해 관심을 끌고자한다. <br>

하나의 쿠키는 3가지 재료를 통해 만들 수 있으며, 각 재료는 정수로 표현된다. <br>
산지니는 새내기의 취향을 조사하여 새내기가 0부터 n까지의 재료들이 나열된 레시피 북에서 쿠키의 재료가 증가하는 수열인 <br>
쿠키를 좋아한다는 것을 알게되었다. <br>

산지니는 시행착오 끝에 새내기가 좋아하는 것으로 의심되는 레시피 북 2개를 찾았다. <br>

```
Looking for attention 너야겠어
확실하게 나로 만들겠어
Stop, eyyy
Drop the question
Drop the, drop the question
Want attention
Wanna want attention
```

산지니는 새내기의  관심을 확실히 끌기 위해서 2개의 레시피 북에서 공통으로 증가하는 수열을 찾고자 한다. <br>

```
가끔은 정말
헷갈리지만
분명한 건
Got me looking for attention
```

산지니가 attention을 확실히 받을 수 있는지 알아보고, 그럴 경우 만들어야하는 쿠키의 개수를 찾아보자

### 입력
```
첫째 줄에 레시피 북의 길이 N이 주어진다.
이어서 둘째 줄과 셋째 줄에 각 레시피 북에 나열된 쿠키의 재료들이 순서대로 나열된다.
```
### 출력
```
산지니가 처음 만든 레시피와 수정한 레시피 중에 새내기의 attention을 받을 수 있는 쿠키가 있으면
첫째 줄에 'My heart has gone to paradise'을 출력하고
둘째 줄에 만들어야 하는 쿠키의 개수를 출력한다.

그리고 확실히 받을 수 있는 쿠키를 찾지 못한다면
'Attention is what I want'를 출력한다.
```

### 예제 입력1
```
3
1 2 0
0 1 2
```

### 예제 출력1
```
Attention is what I want
```

### 예제 입력2
```
5
1 2 3 0 4
1 2 3 4 0
```

### 예제 출력2
```
My heart has gone to paradise
7
```