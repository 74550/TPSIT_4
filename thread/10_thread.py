from time import sleep
from threading import Thread

thread=[]


class Task(Thread):
    def __init__(self, n):
        self.id=n
        Thread.__init__(self)

    def run(self):
        print(f'START thread {self.id}...')
        sleep(5)
        print(f'FINISH thread {self.id}...')

cont=0
t=Task(cont)
for _ in range(10):
    t=Task(cont)
    thread.append(t)
    cont=cont+1

for _ in thread:
    t.start()
    t.join()
    