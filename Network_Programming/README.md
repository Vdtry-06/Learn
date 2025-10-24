## I. TCP
### General
```
Socket socket = new Socket(SERVER_HOST, SERVER_PORT);
socket.setSoTimeout(5000);

<Process Code>

socket.close();
in.close();
out.close();

```
### 1. Character
```
    BufferedReader in = new BufferedReader(new InputStreamReader(socket.getInputStream()));
    PrintWriter out = new PrintWriter(socket.getOutputStream(), true);
    out.println(clientMessage);
    out.flush();
    String[] arr = in.readLine().split(",");
```

### 2. Data
```
    DataInputStream in = new DataInputStream(socket.getInputStream());
    DataOutputStream out = new DataOutputStream(socket.getOutputStream());
    out.writeUTF(clientMessage);
    out.flush();
    int a = in.readInt();
```

### 3. Byte
```
    InputStream in = socket.getInputStream();
    OutputStream out = socket.getOutputStream();
    out.write(clientMessage.getBytes());
    out.flush();
    byte[] buffer = new byte[1024];
    int bytesRead = in.read(buffer);
    if (bytesRead != -1) {
       String serverResponse = new String(buffer, 0, bytesRead);
    }
```

### 4. Object
```
    ObjectInputStream in = new ObjectInputStream(socket.getInputStream());
    ObjectOutputStream out = new ObjectOutputStream(socket.getOutputStream());
    out.writeObject(clientMessage);
    out.flush();
    Product product = (Product) in.readObject();
```

## II. UDP
### General
```
DatagramSocket socket = new DatagramSocket();
InetAddress address = InetAddress.getByName(SERVER_HOST);

String message = "<username><qCode>";
byte[] outBuffer = message.getBytes();
DatagramPacket outPacket = new DatagramPacket(
                outBuffer,
                outBuffer.length,
                address,
                SERVER_PORT
);
socket.send(outPacket);
byte[] inBuffer = new byte[1024];
DatagramPacket inPacket = new DatagramPacket(
                inBuffer, 
                inBuffer.length
);
socket.receive(inPacket);

<Process Code>

socket.isClosed();

```
### 1. String / Data - Type:
```
    byte[] outBuffer = message.getBytes();
    DatagramPacket outPacket = new DatagramPacket(outBuffer, outBuffer.length, address, SERVER_PORT);
    socket.send(outPacket);

    byte[] inBuffer = new byte[1024];
    DatagramPacket inPacket = new DatagramPacket(inBuffer, inBuffer.length);
    socket.receive(inPacket);
```

### 2. Object
```
    String requestId = new String(inPacket.getData(), 0, 8);
    ByteArrayInputStream bis = new ByteArrayInputStream(inPacket.getData(), 8, inPacket.getLength() - 8);
    ObjectInputStream ois = new ObjectInputStream(bis);
    Customer customer = (Customer) ois.readObject();
    ois.close();

    process();
    
    ByteArrayOutputStream bos = new ByteArrayOutputStream();
    ObjectOutputStream oos = new ObjectOutputStream(bos);
    oos.writeObject(customer);
    oos.flush();
    
    byte[] customerBytes = bos.toByteArray();
    outBuffer = new byte[8 + customerBytes.length];
    System.arraycopy(requestId.getBytes(), 0, outBuffer, 0, 8);
    System.arraycopy(customerBytes, 0, outBuffer, 8, customerBytes.length);
    
    outPacket = new DatagramPacket(outBuffer,  outBuffer.length, address, SERVER_PORT);
    socket.send(outPacket);
```

## III. RMI
### General
```
Registry registry = LocateRegistry.getRegistry(SERVER_HOST, 1099);
[Interface Name] service = ([Name Interface]) registry.lookup([RMI Name]);
[Data Type] data = service.<get property request from interface>(username, qCode);

<Process Code>

service.<get property response from interface>(username, qCode, [Name Data Type]);
```
### 1. Byte
```
ByteService service = (ByteService) registry.lookup("RMIByteService");
byte[] data = service.requestData(username, qCode);
service.submitData(username, qCode, <Byte[] Name>);
```
### 2. Chracter
```
CharacterService service = (CharacterService) registry.lookup("RMICharacterService");
String data = service.requestCharacter(username, qCode);
service.submitCharacter(username, qCode, <String Name>);
```
### 3. Data
```
DataService service = (DataService) registry.lookup("RMIDataService");
Integer amount = (Integer) service.requestData(username, qCode);
service.submitData(username, qCode, <String Name>);
```
### 4. Object
```
ObjectService service = (ObjectService) registry.lookup("RMIObjectService");
ProductX productX = (ProductX) service.requestObject(username, qCode);
service.submitObject(username, qCode, <Object Name>);
```