# Author - Tejashri Joshi
# Date - 05-8-2020
# In this file all classes for database tables has been defined
from flask_sqlalchemy import SQLAlchemy

db=SQLAlchemy()

class NFV_providers(db.Model):
    __tablename__="NFV_providers"
    id =db.Column(db.Integer,primary_key=True,autoincrement=True)
    name = db.Column(db.String(100), nullable=False)
    description = db.Column(db.String(1000))

    def __init__(self, name, description):
        self.name = name
        self.description = description

class VNFs(db.Model):
    __tablename__ = "VNFs"
    id = db.Column(db.Integer, primary_key=True,autoincrement=True)
    name = db.Column(db.String(100), nullable=False)
    description = db.Column(db.String(1000))

    def __init__(self, name, description):
        self.name = name
        self.description = description

class QoS_metrics(db.Model):
    __tablename__ = "QoS_metrics"
    id = db.Column(db.Integer, primary_key=True,autoincrement=True)
    name = db.Column(db.String(100), nullable=False)
    beneficial = db.Column(db.Integer)
    description= db.Column(db.String(1000))
    ltCentric = db.Column(db.Integer)
    rtCentric = db.Column(db.Integer)
    tpCentric = db.Column(db.Integer)
    avCentric = db.Column(db.Integer)
    rlCentric = db.Column(db.Integer)

    def __init__(self, name, description,beneficial,ltCentric,rtCentric,tpCentric,avCentric,rlCentric):
        self.name = name
        self.description = description
        self.beneficial=beneficial
        self.ltCentric = ltCentric
        self.rtCentric = rtCentric
        self.tpCentric = tpCentric
        self.avCentric = avCentric
        self.rlCentric = rlCentric



class VNF_QoS(db.Model):
    __tablename__ = "VNF_QOS"
    id = db.Column(db.Integer, primary_key=True,autoincrement=True)
    vnf_id = db.Column(db.Integer, db.ForeignKey("VNFs.id"),nullable=False)
    QoS_id= db.Column(db.Integer, db.ForeignKey("QoS_metrics.id"),nullable=False)

    def __init__(self, vnf_id, QoS_id):
        self.vnf_id = vnf_id
        self.QoS_id = QoS_id

class NFV_VNFs(db.Model):
    __tablename__ = "NFV_VNFs"
    id = db.Column(db.Integer, primary_key=True,autoincrement=True)
    NFV_id = db.Column(db.Integer, db.ForeignKey("NFV_providers.id"),nullable=False)
    vnf_id = db.Column(db.Integer, db.ForeignKey("VNFs.id"),nullable=False)
    QoS_id= db.Column(db.Integer, db.ForeignKey("QoS_metrics.id"),nullable=False)
    QoS_value= db.Column(db.Float,nullable=False)

    def __init__(self, NFV_id, vnf_id,QoS_id,QoS_value):
        self.NFV_id = NFV_id
        self.vnf_id = vnf_id
        self.QoS_id = QoS_id
        self.QoS_value=QoS_value

class NFVsupportedVNFs(db.Model):
    __tablename__ = "NFVsupportedVNFs"
    id = db.Column(db.Integer, primary_key=True,autoincrement=True)
    nfv_id = db.Column(db.Integer, db.ForeignKey("NFV_providers.id"),nullable=False)
    vnf_id = db.Column(db.Integer, db.ForeignKey("VNFs.id"),nullable=False)


    def __init__(self, nfv_id, vnf_id):
        self.nfv_id = nfv_id
        self.vnf_id = vnf_id





