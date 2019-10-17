import numpy as np
import h5py
import matplotlib.pyplot as plt

apa = 0

# data = h5py.File('frame-%d.hdf5'%(apa), 'r')
data = h5py.File('example.hdf5', 'r')
print(data.keys())

tag = 'gauss'
frame = np.array(data['frame_%s%d_0'%(tag,apa)])


plt.figure()

frame_ma = np.ma.array(frame[:,0:800])
plt.imshow(np.ma.masked_where(frame_ma<=0,frame_ma), cmap="rainbow", interpolation="none"
# , extent = [0 , 6000, 0 , 6000]
, origin='lower'
, aspect='auto'
)
plt.colorbar()
plt.xlim([150,250])
plt.ylim([500,2000])
plt.clim([0,5000])
plt.grid()
plt.show()

wave = frame[1450:1520,235]
plt.plot(wave, 'bo')
plt.grid()
plt.show()

print('mean = %f' % np.mean(wave))
print('std. = %f' % np.std(wave))
