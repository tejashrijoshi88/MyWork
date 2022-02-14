# Author - Tejashri Joshi
# Date - 05-8-2020
# this file contains all the routes(REST APIs) defined for the application

from flask import  render_template, jsonify,request
from prepare_data import  *
from Topsis import *
from init import create_app
from insertData import insert
from prepare_data import get_all_QoS

# initiation of flask app
app = create_app()
app.app_context().push()
# create database tables
db.create_all()
# insert data into database tables
insert()

# home route to show menus
@app.route("/",methods=['GET'])
def GetVNFs():
    return render_template("index.html")

# get VNF list
@app.route("/VNF",methods=['GET'])
def GetVNF():
    NFVVNFs=get_nfvsupportedvnfs()
    response=jsonify({"vnf":sorted(NFVVNFs,key=str.lower,reverse=True)})
    return response

# returns performance score for the selcted service provider and VNF
@app.route("/perfScore",methods=['POST'])
def parse_data():
      rank = handlemultipleVnfs(request.form)
      print(rank)
      response= jsonify({"success": True, "name": rank})
      return response
# return the QoS weights for provided scenario
@app.route("/QoS/<Scenario>", methods=['GET'])
def get_all_qos(Scenario):
    QoS=get_all_QoS()
    if QoS is None:
        return jsonify({"error":"No Service Provider available"})
    QoS_names=[]
    QoS_values=[]
    for i in QoS:
        if (Scenario == "lt-Centric"):
          QoS_names.append(i.name)
          QoS_values.append(i.ltCentric)
        elif(Scenario == "rt-Centric"):
          QoS_names.append(i.name)
          QoS_values.append(i.rtCentric)
        elif(Scenario == "tp-Centric"):
          QoS_names.append(i.name)
          QoS_values.append(i.tpCentric)
        elif(Scenario == "av-Centric"):
          QoS_names.append(i.name)
          QoS_values.append(i.avCentric)
        elif (Scenario == "rl-Centric"):
          QoS_names.append(i.name)
          QoS_values.append(i.rlCentric)
        elif(Scenario == "Other"):
          QoS_names.append(i.name)
          QoS_values.append(0)
    print(QoS_values)
    response=jsonify({"name":QoS_names,"value":QoS_values})
    return response

if __name__ =="__main__":
    app.run(host='0.0.0.0')

