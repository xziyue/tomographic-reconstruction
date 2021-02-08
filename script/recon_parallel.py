import pickle
import multiprocessing
import numpy as np
from scipy.interpolate import interp1d

with open('recon_params.pickle', 'rb') as infile:
    recon_params = pickle.load(infile)
   
# load all variables into global namespace
for key, val in recon_params.items():
    globals()[key] = val


val = multiprocessing.Value('i')

def reconstruction_slice(sli):
    sinogram = sli(cbp_radius, cbp_angles)
    result = np.zeros((x_range.size, y_range.size), np.float)
    
    g_funcs = []
    for i in range(cbp_angles.size):
        g_conv = np.convolve(sinogram[i,...], d_filt)
        g_funcs.append(interp1d(conv_ticks, g_conv))
    
    for ind_x, x in enumerate(x_range):
        for ind_y, y in enumerate(y_range):
            g_cartesian = x * np.cos(cbp_angles) + y * np.sin(cbp_angles)
            int_vals = []
            for i in range(len(g_funcs)):
                int_vals.append(g_funcs[i](g_cartesian[i]))

            integral = np.trapz(int_vals, dx=cbp_angles[1] - cbp_angles[0])
            result[ind_x, ind_y] = integral
    
    val.value += 1
    print('{}/{}'.format(val.value, len(radon_slices)), flush=True)
    return result
    

pool = multiprocessing.Pool(n_tasks)
recons = pool.map(reconstruction_slice, radon_slices, chunksize=5)
with open('recon.pickle', 'wb') as infile:
    pickle.dump(recons, infile)

print('fin')
