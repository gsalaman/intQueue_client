void setup() 
{
  intQueueRetType retVal;
  int myElement;
  int i;
  intQueue myQueue;
  
  Serial.begin(9600);

  myQueue.print("Init state");

  //test one:  read from empty buffer.
  retVal = myQueue.get(&myElement);
  if (retVal)
  {
    //  expected failure...good.
    myQueue.print("Empty test succeeded, ret error");
  }
  else
  {
    myQueue.print("Empty test failed...gave a valid read");
    Serial.print(myElement);
  }

  // Test two:  fill the buffer
  i=10;
  do
  {
    retVal = myQueue.put(&i);
    i+=10;
    myQueue.print("adding elements");
  }
  while (retVal == 0);

  myQueue.print("done adding");
  
  // test three:  read two elements out.
  retVal = myQueue.get(&myElement);
  myQueue.print("read first");
  Serial.print("element: ");
  Serial.println(myElement);
  if (retVal) Serial.print("FIRST READ FAIL!!!");
  retVal = myQueue.get(&myElement);
  myQueue.print("read second");
  Serial.print("element: ");
  Serial.println(myElement);
  if (retVal) Serial.print("SECOND READ FAIL!!!");

  // test four:  keep putting until buffer full again.
  do
  {
    retVal = myQueue.put(&i);
    i+=10;
    myQueue.print("adding elements");
  }
  while (retVal == 0);

  myQueue.print("done adding");

  // Test five:  read until empty.
  while (myQueue.numElements())
  {
    retVal = myQueue.get(&myElement);
    Serial.print("element: ");
    Serial.println(myElement);
    myQueue.print("read");
  }

  // test six...read one more.
  retVal = myQueue.get(&myElement);
  Serial.print("last read retval: ");
  Serial.println(retVal);
  myQueue.print("done");
}

void loop() 
{
 

  
}
