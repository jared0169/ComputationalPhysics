# File: ch1-4_plot.py
#
# Plots the data from the ch1_4.cpp program

from pylab import *
import csv

def main():
    filesDict = { "ch1-4_ratio1.csv":"ch1-4_ratio1.png",
                  "ch1-4_ratio1_2.csv":"ch1-4_ratio1_2.png",
                  "ch1-4_ratio1_4.csv":"ch1-4_ratio1_4.png",
                  "ch1-4_ratio1_10.csv":"ch1-4_ratio1_10.png",
                  "ch1-4_ratio10_1.csv":"ch1-4_ratio10_1.png"}

    for fieldname in filesDict.keys():
        f = open(fieldname,"r")
        f_dict = csv.DictReader(f)

        time = []
        n_a = []
        n_b = []

        for row in f_dict:
            time.append(float(row["time"]))
            n_a.append(float(row["nuclei_a"]))
            n_b.append(float(row["nuclei_b"]))

        plot(time,n_a,label="N_a "+f_dict.fieldnames[-2])
        plot(time,n_b,label="N_b "+f_dict.fieldnames[-1])
        legend()
        savefig(filesDict[fieldname],dpi=(640/8))
        show()
        f.close()

if __name__ == "__main__":
    main()
