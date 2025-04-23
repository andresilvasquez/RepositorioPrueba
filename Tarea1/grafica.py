import pandas as pd 
import matplotlib.pyplot as plt 
import seaborn as sns

sns.set(style="whitegrid", context="notebook")

df = pd.read_csv("datos2.txt", sep="\s+", header=None, names=["N","sumup","sumdown","diff"])

plt.figure(figsize=(8,5))
sns.lineplot(data=df, x="N",y="diff")
plt.yscale("log")
plt.xscale("log")
plt.xlabel("N")
plt.ylabel(r"$|1-\frac{S_1}{S_2}|$")
plt.title("Diferencia relativa entre las sumas en función N")
plt.grid(True)
plt.tight_layout()
plt.show()
