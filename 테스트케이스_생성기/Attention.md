### Attention

```python
import random

file = open('generate_random.inp', 'w')
N = random.randrange(3, 100000)

file.write(str(N) + '\n')

B = [str(x) for x in range(N)]
random.shuffle(B)

for i in range(N - 1) :
    b = B[i]                    # 겹치지 않게 설정함
    file.write(B[i] + ' ')
file.write(B[N - 1] + '\n')

random.shuffle(B)

for i in range(N - 1) :
    b = B[i]                    # 겹치지 않게 설정함
    file.write(B[i] + ' ')
file.write(B[N - 1] + '\n')

```