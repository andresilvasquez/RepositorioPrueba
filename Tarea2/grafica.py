import pandas as pd 
import matplotlib.pyplot as plt 
import seaborn as sns

sns.set(style="whitegrid", context="notebook")

df1 = pd.read_csv("datos1.txt", sep="\s+", header=None, names=["x","pdf"])
df2 = pd.read_csv("datos2.txt", sep="\s+", header=None, names=["x","pdf"])
df5 = pd.read_csv("datos5.txt", sep="\s+", header=None, names=["x","pdf"])

plt.figure(figsize=(8,5))
sns.lineplot(data=df1, x="x",y="pdf",label="seed = 1")
sns.lineplot(data=df2, x="x",y="pdf",label="seed = 2")
sns.lineplot(data=df5, x="x",y="pdf",label="seed = 5")
#plt.yscale("log")
#plt.xscale("log")
plt.xlabel("x")
plt.ylabel("pdf(x)")
plt.title("pdf(x) para distintas seed")
plt.legend()
plt.grid(True)
plt.tight_layout()
plt.show()
