
import numpy as np
import matplotlib.pyplot as plt

f_x = open('input_d.txt', 'r')
x = np.array([])
noise = np.array([])
z = np.array([])
sins = np.array([])
with open('input_d.txt', 'r') as f_x:
    for line in f_x:
        datan, datax = line.strip().split()
        x = np.append(float(datax), x)
        noise = np.append(float(datan), noise)

for i in range(noise.shape[0]):
    z_i = np.sin(i) + noise[i] 
    z = np.append(z_i,z)
    sins = np.append(np.sin(i), sins)
    
nul = np.array([i for i in range(noise.shape[0])])
plt.plot(nul, sins, "-")
plt.plot(nul, z, "--")
plt.plot(nul, x, ":")
plt.legend(['sin', 'signal', 'filtered signal'])
plt.grid()
plt.show()
