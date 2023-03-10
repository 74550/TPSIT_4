import random
import time

n=10000000
l=[random.uniform(0.,1.)for _ in range(n)]
start_time=time.time()   #partenza del tempo
maximum=l[0]
#maximum=max(1) ----> stesso metodo, più veloce (max è una funz)
for element in l:
    if element > maximum:
        maximum=element
end_time=time.time()  #stop del tempo
print(f"il massimo è {maximum}")

print(f"durata dell'algoritmo: {end_time-start_time}s")