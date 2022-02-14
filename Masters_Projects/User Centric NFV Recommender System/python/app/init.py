# Author - Tejashri Joshi
# Date - 05-8-2020
# this file contains initiation of flask app

from flask import Flask, render_template, jsonify,request
import config
from models import *


def create_app():

    flask_app = Flask(__name__)
    print(config.DATABASE_CONNECTION_URI)
    flask_app.config["SQLALCHEMY_DATABASE_URI"]=config.DATABASE_CONNECTION_URI #'mysql://root:Teju@2019@localhost/ucnfv'
    flask_app.config["SQLALCHEMY_TRACk_MODIFICATIONS"] = False
    db.init_app(flask_app)
    return flask_app
