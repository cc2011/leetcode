struct CacheNode{
    int key;
    int value;
    CacheNode(int k, int v): key(k), value(v) {}
};

class LRUCache{
    
public:
    LRUCache(int capacity) {
        this->capacity = capacity;
    }
    
    int get(int key) {
        if(cacheMap.find(key) == cacheMap.end()){ //cacheMap[key] == 0
            return -1;
        }
        else { //������map���ҵ���key: 1.�ѽڵ�ŵ�����ͷ, 2.����map�еļ�¼, 3.����value
            cacheList.splice(cacheList.begin(), cacheList, cacheMap[key]);
            cacheMap[key] = cacheList.begin();
            return cacheList.front().value;
        }
    }
    
    void set(int key, int value) {
        if(cacheMap.find(key) == cacheMap.end()) {    //û���ҵ��ڵ�: 1.����ڵ㲢����list��map, 2.Ҫ����Ƿ�����
            if(cacheList.size() == capacity){ //����, ɾ��ĩβ�Ľڵ�
                cacheMap.erase(cacheList.back().key); //mapҪ�ȵ���
                cacheList.pop_back();   
            }
            //�½ڵ�嵽ͷ��, ����map
            cacheList.push_front(CacheNode(key, value));
            cacheMap[key] = cacheList.begin(); //���½ڵ�λ��
        }
        else{   //�ҵ��ڵ�Ļ�, ֻ��Ҫ�ѽڵ������ͷ��, ����map
            cacheList.splice(cacheList.begin(), cacheList, cacheMap[key]);
            cacheMap[key] = cacheList.begin(); //����map
            cacheMap[key]->value = value;   //����value
        }
    }
private:
    int capacity;
    list<CacheNode> cacheList;
    unordered_map<int, list<CacheNode>::iterator> cacheMap;  
};