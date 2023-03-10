from time import sleep
from threading import Thread

class Task(Thread):
    def __init__(self, n,temp):
        self.cont=n
        self.temp=temp
        Thread.__init__(self)

    def run(self):
        print(f'START thread {self.cont}...')
        sleep(5)
        print(f'FINISH thread {self.cont}...')

#creo 2 nuovi thread e passo l'ID e il tempo che voglio che rimangano in attesa
t1=Task(1,5)
t2=Task(2,3)
#inizializzo il thread
t1.start()   #fa partire il run
t2.start()
#aspetto il tempo di attesa dei thread
t1.join()
t2.join()