package test;

public class Client {
    public static void main(String[] args) {

    }

    private static void TCP() {
        // TCP
        /*
            Socket socket = new Socket(SERVER_HOST, SERVER_PORT);
            socket.soSetTimeout(5000);

            // process

            socket.close();
            in.close();
            out.close();
        */
        //  TCP Object
        /*
            ObjectOutputStream out = new ObjectOutputStream(socket.getOutputStream());
            ObjectInputStream in = new ObjectInputStream(socket.getInputStream());

            out.writeObject("B22DCCN866;qCode");
            out.flush();

            Product product = (Product) in.readObject();
            // process

            out.writeObject(product);
            out.flush();

        */
        // TCP Datastream
        /*
            DataOutputStream out = new DataOutputStream(socket.getOutputStream());
            DataInputStream in = new DataInputStream(socket.getInputStream());

            out.writeUTF("B22DCCN866;qcode");
            out.flush();

            Integer a = in.writeInt();

            // process

            out.writeUTF(sendServer);
            out.flush();
        */
        // TCP Characterstream
        /*
            BufferReader in = new BufferReader(new InputStream(socket.getInputStream()));
            PrintWriter out = new PrintWriter(socket.getOutputStream(), true);
            out.println("B22DCCN866;qCode");
            out.flush();

            String response = in.readline();
            // process

            out.println(sendServer);
            out.flush();
        */

        // TCP ByteStream
        /*
            InputStream in = socket.getInputStream();
            OutputStream out = socket.getOutputStream();

            out.write("B22DCCN866;qCode".getBytes());
            out.flush();

            byte[] buffer = new byte[1024];
            int byteReads = in.read(buffer);
            if (byteReads != -1) {
                String[] arr = new String(buffer, 0, byteReads).split("\\|");
                // process

                out.write(sendServer.getBytes());
                out.flush();
            }

        */
    }

    private static void UDP() {
        // UDP
        /*
            DatagramSocket socket = new DatagramSocket();
            InetAddress address = socket.getByName(SERVER_HOST);

            byte[] outBuffer = ";B22DCCN866;qCode".getBytes();
            DatagramPacket outPacket = new DatagramPacket(outBuffer, outBuffer.length, address, SERVER_PORT);
            socket.send(outPacket);

            byte[] inBuffer = new byte[1024];
            DatagramPacket inPacket = new DatagramPacket(inBuffer, inBuffer.length);
            socket.recieve(inPacket);

            // process;

            socket.isClosed();
        */
        // UDP String
        /*
            String[] arr = new String(inPacket.getData(), 0, inPacket.getLength()).split(";");
            String requestId = arr[0];
            String data = arr[1];
            
            // process
            
            outBuffer = sendData.getBytes();
            outPacket = new DatagramPacket(outBuffer, outBuffer.length, address, SERVER_PORT);
            socket.send(outPacket);
        */
        
        // UDP DataType
        /*
            String requestId = new String(inPacket.getData(), 0, 8);
            String data = new String(inPacket.getData(), 8, inPacket.getLength() - 8);
            
            // process
            
            outBuffer = sendServer.getBytes();
            outPacket = new DatagramPacket(outBuffer, outBuffer.length, address, SERVER_HOST);
            socket.send(outPacket);
        */
        
        // UDP Object
        /*
            String requestId = new String(inPacket.getData(), 0, 8);
            
            ByteArrayInputStream bis = new ByteArrayInputStream(inPacket.getData(), 8, inPacket.getLength() - 8);
            ObjectInputStream ois = new ObjectInputStream(bis);
            Product product = (Product) ois.writeObject();
            ois.close()
            
            // process
            
            ByteArrayOutputStream bos = new ByteArrayOutputStream();
            ObjectOutputStream oos = new ObjectOutputStream(bos);
            oos.readObject();
            oos.close();

            byte[] productBytes = bos.toByteArray();
            outBuffer = new byte[8 + productBytes.length];
            
            System.arraycopy(requestId.getBytes(), 0, outBuffer, 0, 8);
            System.arraycopy(productBytes, 0, outBuffer, 8, productBytes.length);

            outPacket = new DatagramPacket(outBuffer, outBuffer.length, address, SERVER_PORT);
            socket.send(outPacket);
        */
    }

    private static void RMI() {
        // RMI Object
        /*
            Registry registry = LocateRegistry.getRegistry(SERVER_HOST, 1099);
            ObjectService service = (ObjectSerice) registry.lookup("RMIObjectService");

            Product product = (Product) service.requestObject("B22DCCN866", "qCode");
            // process

            service.submitObject("B22DCCN866", "qCode", product);
        */
        // RMI Character
        /*
            Registry registry = LocateRegistry.getRegistry(SERVER_HOST, 1099);
            CharacterService service = (CharacterService) registry.lookup("RMICharacterService");

            String data = service.requestCharacter("studentCode", "qCode");
            // process

            service.submitCharacter(studentCode, qCode, sendServer);

        */
        // RMI Byte
        /*
            Registry registry = LocateRegistry.getRegistry(SERVER_HOST, 1099);
            ByteService service = (ByteService) registry.lookup("RMIByteService");

            byte[] data = service.requestData(studentCode, qCode);

            // process

            service.submitData(studentCode, qCode, sendServer);
        */
    }

    private static void WS() {
        // WS ObjectService
        /*
            ObjectService_Service service = new ObjectService_Service();
            ObjectService port = service.getObjectServicePort();

            List<EmployeeY> response = port.requestListEmployeeY(studentCode, qCode);
            // process

            port.submitListEmployeeY(studentCode, qCode, response);
        */

        // WS DataService / CharacterService
        /*
            DataService_Service service = new DataService_Service();
            DataService port = service.getDataServicePort();

            List<Integer> list = port.getData(studentCode, qCode);
            // process

            port.submitDataStringArray(studentCode, qCode);
        */
    }
}
