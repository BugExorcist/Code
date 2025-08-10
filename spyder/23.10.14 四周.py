import pymongo
# 创建客户端
client = pymongo.MongoClient(host='localhost', port=27017, connect=False)
print(client)

db = client.get_database('pia')
print(db)

# # 查询所有的数据库
for name in client.list_database_names():
  print(name)

# client.drop_database('pia')

# for name in client.list_database_names():
#     print(name)

col1 = db.get_collection('col')
print(col1)

col2 = db.get_collection('col11')
print(col2)

for name in client.list_database_names():
  print(name)

def test_insert():
  users = client.pia.x1
  doc1 = {"name":"ls","age":100,'sex':'女'}
  doc2 = {"name":"ww","age":50,'sex':'男'}
  doc3 = {"name":"zs","age":50,'sex':'男'}
  rs = users.insert_many([doc1,doc2,doc3],ordered=True)
  print(rs.acknowledged,rs.inserted_ids)

def test_delete():
    users = client.pia.x1
    r = users.delete_one({"name":"ls"})
    print(r.acknowledged,r.deleted_count)

def test_updata():
    users = client.pia.x1
    r = users.update_one(filter={'name':'zs'},update={'$set':{'age':100,'sex':'女'}})
    (r.acknowledged,r.matched_count,r.modified_count,r.raw_result,r.upserted_id)

def show(rs):
    for r in rs:
        print(r)

def search_and():
    users = client.xk.x1
    r = users.find({'name':'zs','age':100})
    print(r)
    show(r)

##test_insert()
#test_delete()
test_updata

users = client.pia.x1
rs = users.find()
show(rs)

search_and()
