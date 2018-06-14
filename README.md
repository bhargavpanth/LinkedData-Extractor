## Linked Data Extractor

---

### What does this do?

* C/Python implementation to extract unique vocabularies from a linked dataset

---

### How to run?

* ```git clone https://github.com/bhargavpanth/LinkedData-Extractor.git```
* ```python setup.py build```
* ```python setup.py install``` use ```sudo``` if required

### Run HDFS jobs

* Streaming JAR location ```/usr/local/hadoop/hadoop-streaming-2.7.3.jar```
* Set alias ```alias hadoop='/usr/local/hadoop/hadoop-2.8.4/bin/hadoop'``` in ```zshrc``` or ```bashrc```
* cmd ```hadoop jar /usr/local/hadoop/hadoop-streaming-2.7.3.jar -mapper ./job/Map/mapper.py -reducer ./job/Reduce/reducer.py -file ./job/Map/mapper.py -file ./job/Reduce/reducer.py -input data/test.hdt -output joboutput```


### HDFS in general

```
hadoop jar hadoop-streaming-2.9.1.jar \
  -input myInputDirs \
  -output myOutputDir \
  -mapper /bin/cat \
  -reducer /usr/bin/wc
```

* Run HDFS on TCD instance

* Hadoop streaming JAR is placed here ```/usr/local/hadoop/hadoop-streaming-2.7.3.jar```
* Alias for Hadoop set in bash profile

