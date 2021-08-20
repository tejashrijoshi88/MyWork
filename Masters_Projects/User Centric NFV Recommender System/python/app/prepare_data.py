# Author - Tejashri Joshi
# Date - 05-10-2020
# This file contains small functions are written to fetch data from database and helper functions
from models import *
from Topsis import *

# return QoS for given id
def get_QoS(QoS_id):
    QoS = QoS_metrics.query.filter_by(id=QoS_id).first()
    return QoS

# return a NFV for given id
def get_NFV(NFV_id):
    NFV = NFV_providers.query.filter_by(id=NFV_id).first()
    return NFV.name

# return a VNF for given id
def get_VNF(VNF_id):
  VNF = VNFs.query.filter_by(id=VNF_id).first()
  return VNF.name

# all VNFs for each service provider
def get_nfvsupportedvnfs():
    NFVVNFs=[]
    nfvSupportedvnfs = NFVsupportedVNFs.query.all()
    for i in nfvSupportedvnfs:
      NFVVNFs.append(get_VNF(i.vnf_id)+"-"+get_NFV(i.nfv_id))
    return NFVVNFs

# get all service provders for VNF
def get_NFVs(VNF_id):
    NFVs = []
    NFV_ids= NFVsupportedVNFs.query.filter_by(vnf_id=VNF_id).all()
    for i in NFV_ids:
        NFVs.append(i.nfv_id)
    return NFVs

# get QoS details for a VNF
def get_QoSIds(VNF_id):
    QoS = []
    QoS_ids= VNF_QoS.query.filter_by(vnf_id=VNF_id).all()
    for i in QoS_ids:
        QoS.append(i.QoS_id)
    return QoS

# return all QoS details
def get_all_QoS():
    QoS=QoS_metrics.query.all()
    return QoS

# function to calculate the performance score when multiple VNFs selected
def handlemultipleVnfs(thisdict):
  total = 0
  count = 0
  VNFs=[]
  for key in thisdict:
    if (key.startswith("VNF")):
      VNFs.append(thisdict.get(key))
  for i in VNFs:
    count = count + 1
    print(thisdict)
    print(i.split("-")[0])
    # call prepare data
    Weight, beneficial, attributes, alternatives = prepare_data(thisdict, i.split("-")[0])
    # call TOPSIS to calculate perf score
    score = topsis(Weight, beneficial, attributes, alternatives)
    print(score)
    total = total + score.loc[i.split("-")[1]]
  return total / count

# takes input from user and prepare list of weight, beneficial,attributes and alternatives
def prepare_data(thisdict,VNF):
    beneficial = []
    Weight = []
    attributes = []
    alternatives = []
    print(VNF)
    # get VNF id for provided VNF
    VNF_id = VNFs.query.filter_by(name=VNF).first()
    print(VNF_id.id)
    # get service providers for the VNF
    NFVs=get_NFVs(VNF_id.id)
    # get QoS attributes supported for VNF
    QoS=get_QoSIds(VNF_id.id)
    count=0
    # prepare the list of weights , beneficial for each QoS attribute
    for i in NFVs:
        QoS_values = []
        for j in QoS:
            data = NFV_VNFs.query.filter_by(NFV_id=i,QoS_id=j,vnf_id=VNF_id.id).first()
            print(i,j)
            if count==0:
                QoSdetails = get_QoS(j)
                beneficial.append(QoSdetails.beneficial)
                print(QoSdetails.name)
                print(thisdict.get(QoSdetails.name))
                print(thisdict.get("Latency"))
                Weight.append(float(thisdict.get(QoSdetails.name)))
            QoS_values.append(data.QoS_value)
        # prepare attributes and alternatives
        attributes.append(QoS_values)
        alternatives.append(get_NFV(i))
        count = count + 1
    print(attributes)
    print(alternatives)
    print(beneficial)
    print(Weight)
    return Weight,beneficial,attributes,alternatives





