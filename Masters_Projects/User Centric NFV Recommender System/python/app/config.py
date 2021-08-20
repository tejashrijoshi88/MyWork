# Author - Tejashri Joshi
# Date - 05-8-2020
# this file contains all the environment variables and create DB Connection URI
import os

user = os.environ.get('MYSQL_USER')
password = os.environ.get('MYSQL_PASSWORD')
host = os.environ.get('MYSQL_HOST')
port = os.environ.get('MYSQL_PORT')
database = os.environ.get('MYSQL_DB')

DATABASE_CONNECTION_URI =f'mysql://{user}:{password}@{host}/{database}'