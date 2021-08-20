# Author - Tejashri Joshi
# Date - 05-15-2020
# file is written to get data from csv files and insert into database tables
import csv
from models import *
from init import create_app

def insert():
# insert data into NFV_providers ,VNFs tables
    f1= open("NFV_VNFs.csv")
    reader=csv.reader(f1)
    for NFV , VNF  in reader:
        #print(NFV,VNF)
        NFV_exists = db.session.query(db.exists().where(NFV_providers.name == NFV)).scalar()
        if (NFV_exists is False):
            NFV= NFV_providers(name=NFV,description='')
            db.session.add(NFV)
            db.session.commit()
        VNF_exists = db.session.query(db.exists().where(VNFs.name == VNF)).scalar()
        if (VNF_exists is False):
            VNF= VNFs(name=VNF,description='')
            db.session.add(VNF)
            db.session.commit()

# insert data into NFV_VNFs table
    f1 = open("NFV_VNFs.csv")
    reader = csv.reader(f1)
    for NFV, VNF in reader:
        NFV_id = NFV_providers.query.filter_by(name=NFV).first()
        #print(NFV_id.id)
        VNF_id = VNFs.query.filter_by(name=VNF).first()
        #print(VNF_id.id)
        check= NFVsupportedVNFs.query.filter_by(nfv_id = NFV_id.id , vnf_id= VNF_id.id).first()
        #print(check)
        if(check is None):
            NVFforVNF = NFVsupportedVNFs(nfv_id=NFV_id.id,vnf_id=VNF_id.id)
            db.session.add(NVFforVNF)
            db.session.commit()

# insert data into QoS_metrics , VNF_QoS tables
    f2= open("VNF_QoS.csv")
    reader=csv.reader(f2)
    for VNF , QoS ,lt,rt,tp,av,rl,beneficial in reader:
        QoS_exists = db.session.query(db.exists().where(QoS_metrics.name == QoS)).scalar()
        if (QoS_exists is False):
            QoSs= QoS_metrics(name=QoS,description='',beneficial=beneficial,ltCentric=lt,rtCentric=rt,tpCentric=tp,avCentric=av,rlCentric=rl)
            db.session.add(QoSs)
        db.session.commit()
        QoS_id = QoS_metrics.query.filter_by(name= QoS).first()
        VNF_id = VNFs.query.filter_by(name=VNF).first()
        VNF_QoS_exists = VNF_QoS.query.filter_by(vnf_id = VNF_id.id , QoS_id=QoS_id.id).first()
        if(VNF_QoS_exists is None):
            VNFQoS = VNF_QoS(vnf_id=VNF_id.id,QoS_id=QoS_id.id)
            db.session.add(VNFQoS)
            db.session.commit()

# insert data into NFV_VNFs table for each QoS attribute
    f3= open("NFV_QoS_values.csv")
    reader=csv.reader(f3)
    #for Latency,Throughput,Availability,Jitter,Cost,CPU ,Memory,ResponseTime,Security,Reliability,VNF, NFV  in reader:
    for ResponseTime,Availability , Throughput, Reliability,Latency, VNF, NFV in reader:
        VNF_id = VNFs.query.filter_by(name=VNF).first()
        NFV_id = NFV_providers.query.filter_by(name=NFV).first()

        QoS_id = QoS_metrics.query.filter_by(name='Response Time').first()
        QoSExists=VNF_QoS.query.filter_by(vnf_id=VNF_id.id, QoS_id=QoS_id.id).first()
        if QoSExists != None:
            check_row_exists = NFV_VNFs.query.filter_by(NFV_id = NFV_id.id,QoS_id=QoS_id.id,vnf_id = VNF_id.id).first()
            if check_row_exists is None:
                NFVVNF_ResponseTime= NFV_VNFs(NFV_id=NFV_id.id,vnf_id=VNF_id.id,QoS_id=QoS_id.id,QoS_value=ResponseTime)
                db.session.add(NFVVNF_ResponseTime)
                db.session.commit()

        QoS_id = QoS_metrics.query.filter_by(name='Latency').first()
        print(NFV_id.id,VNF_id.id,QoS_id.id,Latency)
        QoSExists= VNF_QoS.query.filter_by(vnf_id = VNF_id.id,QoS_id=QoS_id.id).first()
        if QoSExists != None:
            check_row_exists = NFV_VNFs.query.filter_by(NFV_id = NFV_id.id,QoS_id=QoS_id.id,vnf_id = VNF_id.id).first()
            if check_row_exists is None:
                print(check_row_exists)
                NFVVNF_latency= NFV_VNFs(NFV_id=NFV_id.id,vnf_id=VNF_id.id,QoS_id=QoS_id.id,QoS_value=Latency)
                db.session.add(NFVVNF_latency)
                db.session.commit()

        QoS_id = QoS_metrics.query.filter_by(name='Throughput').first()
        QoSExists=VNF_QoS.query.filter_by(vnf_id=VNF_id.id, QoS_id=QoS_id.id).first()
        if QoSExists != None:
            check_row_exists = NFV_VNFs.query.filter_by(NFV_id = NFV_id.id,QoS_id=QoS_id.id,vnf_id = VNF_id.id).first()
            if check_row_exists is None:
                NFVVNF_Throughput = NFV_VNFs(NFV_id=NFV_id.id, vnf_id=VNF_id.id, QoS_id=QoS_id.id, QoS_value=Throughput)
                db.session.add(NFVVNF_Throughput)
                db.session.commit()

        QoS_id = QoS_metrics.query.filter_by(name='Availability').first()
        QoSExists=VNF_QoS.query.filter_by(vnf_id=VNF_id.id, QoS_id=QoS_id.id).first()
        if QoSExists != None:
            check_row_exists = NFV_VNFs.query.filter_by(NFV_id = NFV_id.id,QoS_id=QoS_id.id,vnf_id = VNF_id.id).first()
            if check_row_exists is None:
                NFVVNF_Availability= NFV_VNFs(NFV_id=NFV_id.id,vnf_id=VNF_id.id,QoS_id=QoS_id.id,QoS_value=Availability)
                db.session.add(NFVVNF_Availability)
                db.session.commit()

        QoS_id = QoS_metrics.query.filter_by(name='Reliability').first()
        QoSExists=VNF_QoS.query.filter_by(vnf_id=VNF_id.id, QoS_id=QoS_id.id).first()
        if QoSExists != None:
            check_row_exists = NFV_VNFs.query.filter_by(NFV_id = NFV_id.id,QoS_id=QoS_id.id,vnf_id = VNF_id.id).first()
            if check_row_exists is None:
                NFVVNF_Reliability= NFV_VNFs(NFV_id=NFV_id.id,vnf_id=VNF_id.id,QoS_id=QoS_id.id,QoS_value=Reliability)
                db.session.add(NFVVNF_Reliability)
                db.session.commit()

        db.session.commit()
