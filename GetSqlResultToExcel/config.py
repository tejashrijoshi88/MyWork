import os

# save the connection variavles to environment variables in edit configuration and get environment variables
user = os.environ.get('USER')
password = os.environ.get('PASSWORD')
host = os.environ.get('HOST')
port = os.environ.get('PORT')
database = os.environ.get('DB')

# create connection string
DATABASE_CONNECTION_URI =('DRIVER={ODBC Driver 17 for SQL Server};SERVER='+host+';DATABASE='+database+';UID='+user+';PWD='+ password)
