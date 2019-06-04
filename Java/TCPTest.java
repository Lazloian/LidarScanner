import java.io.IOException;
import java.io.PrintWriter;
import java.net.ServerSocket;
import java.net.Socket;
import java.util.Scanner;

public class TCPTest
{
    public static void main(String[] args) throws IOException
    {
        try (ServerSocket listener = new ServerSocket(59090))
        {
            System.out.println("The server is running...");
            while (true)
            {
                try (Socket socket = listener.accept())
                {
                    System.out.println("Connected: " + socket);

                    try 
                    {
                        Scanner data = new Scanner(socket.getInputStream());
                        while (data.hasNextLine())
                        {
                            System.out.println(data.nextLine());
                        }
                    }

                    catch (Exception e)
                    {
                        System.out.println("Error: " + socket);
                    }
                }
            }
        }
    }
}