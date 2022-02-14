import pyodbc
import pandas as pd
import config
import openpyxl

# connection to database
cnxn = pyodbc.connect(config.DATABASE_CONNECTION_URI)
cursor = cnxn.cursor()

# database query
script = """
SELECT * FROM Users
"""
# execution of query
cursor.execute(script)

# get data from query
columns = [desc[0] for desc in cursor.description]
data = cursor.fetchall()

# read data and save to excel
pd.read_sql(script,cnxn).to_excel('abc.xlsx',sheet_name='bar')

#### another way of saving the excel ###

# convert data to dataframe
df = pd.DataFrame([tuple(t) for t in data], columns=columns)

#write dataframe to excel
writer = pd.ExcelWriter('foo.xlsx')
df.to_excel(writer, sheet_name='bar')
writer.save()