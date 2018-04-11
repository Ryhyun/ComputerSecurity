import numpy as np
from scipy.integrate import odeint
import matplotlib.pyplot as plt


N = 1000000
I0, R0 = 1, 0
S0 = N - I0 - R0
beta = 0.8 / N
gamma=  0.05
t = np.linspace(0, 50, 50)

def deriv(y, t, beta, gamma):
    S, I, R = y
    dSdt = -beta * S * I
    dIdt = beta * S * I - gamma * I
    dRdt = gamma * I
    return dSdt, dIdt, dRdt

y0 = S0, I0, R0
ret = odeint(deriv, y0, t, args=( beta, gamma))
S, I, R = ret.T

fig = plt.figure(facecolor='w')
plt.plot(t, S, 'b', alpha=0.5, lw=2, label='Susceptible')
plt.plot(t, I, 'r', alpha=0.5, lw=2, label='Infected')
plt.plot(t, R, 'g', alpha=0.5, lw=2, label='Recovered with immunity')
plt.xlabel('Time ')
plt.ylabel('Number ')
plt.grid(b=True, which='major', c='w', lw=2, ls='-')
legend = plt.legend()
legend.get_frame().set_alpha(0.5)
plt.show()