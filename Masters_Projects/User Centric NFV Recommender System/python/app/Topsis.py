# Author - Tejashri Joshi
# Date - 05-8-2020
# this file contains code to implement TOPSIS algorithm
import numpy as np
import pandas as pd

def topsis(Weight,beneficial,attributes,alternatives):
    #df = pd.read_excel("NFV data.xlsx")
    #Weight = [0.25, 0.5, 0.4, 0.8, 0.2, 0.6]
    #beneficial = [0, 1, 1, 1, 0, 0]
    #attributes = df.iloc[:, 1:].values
    print(attributes)
    print(alternatives)
    Data = pd.DataFrame(attributes, index=alternatives)
    print(Data)
    # get normalized matrix
    DataNorm = Data / np.sqrt(np.power(Data, 2).sum(axis=0))
    print(DataNorm)
    # get weighted matrix
    DataWeighted = DataNorm * Weight
    print(DataWeighted)
    # calculate ideal positive
    ideal_positive = []
    for i in range(len(beneficial)):
        if beneficial[i] == 1:
            value = DataWeighted.iloc[:, i].max()
            ideal_positive.append(value)
        else:
            value = DataWeighted.iloc[:, i].min()
            ideal_positive.append(value)
    # calculate ideal negative
    ideal_negative = []
    for i in range(len(beneficial)):
        if beneficial[i] == 1:
            value = DataWeighted.iloc[:, i].min()
            ideal_negative.append(value)
        else:
            value = DataWeighted.iloc[:, i].max()
            ideal_negative.append(value)

    print(ideal_positive)
    print(ideal_negative)
    # calculate euclidean distance from ideal positive and ideal negative
    S_Positive = np.sqrt(np.power((DataWeighted - ideal_positive), 2).sum(axis=1))
    S_Negative = np.sqrt(np.power((DataWeighted - ideal_negative), 2).sum(axis=1))

    print(S_Positive)
    print(S_Negative)
    # logic to check denominator for zero
    NonZeroDenominator = np.array([1 / i if i != 0 else 0 for i in (S_Negative + S_Positive)])
    # calculate performance score
    perf_score = S_Negative * NonZeroDenominator
    print(perf_score)
    return(perf_score)






