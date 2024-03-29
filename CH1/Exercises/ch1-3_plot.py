# File: ch1-3_plot.py
#
# Plots the data generated by ch1_3.cpp

import pylab
import csv

def main():
    f = open("ch1-3.csv","r")
    f_dict = csv.DictReader(f)

    time = []
    v_numeric = []
    v_actual = []

    print f_dict.fieldnames
    for row in f_dict:
        time.append(float(row["time"]))
        v_numeric.append(float(row["v_numeric"]))
        v_actual.append(float(row["v_actual"]))

    pylab.plot(time,v_actual,label="Actual")
    pylab.plot(time,v_numeric,label="Numeric")
    pylab.legend()
    pylab.show()




if __name__ == "__main__":
    main()
