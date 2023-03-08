### Stop & Go

```python
import random

file = open('generate_random.inp', 'w')
#N = random.randrange(2, 100000)
N = 10
T = random.randrange(2, 10)
file.write(str(N) + ' ' + str(T) + '\n')

B = [x for x in range(100000)]
random.shuffle(B)

for i in range(N) :
    a = random.randrange(1, 3)  # 도로의 번호는 1 또는 2
    b = B[i]                    # 차량 번호는 겹치지 않게 설정함
    c = random.randrange(T, 100000, T) # 최적화 실패....
    
    file.write(str(a) + ' ' + str(b) + ' ' + str(c) + '\n')
```