import java.security.MessageDigest;
import java.security.NoSuchAlgorithmException;
import java.util.Scanner;

public class MD5Demo {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter text to calculate MD5: ");
        String input = sc.nextLine();

        try {
            MessageDigest md = MessageDigest.getInstance("MD5");
            byte[] digest = md.digest(input.getBytes());

            StringBuilder sb = new StringBuilder();
            for (byte b : digest) {
                sb.append(String.format("%02x", b & 0xff));
            }

            System.out.println("MD5 Digest (hex): " + sb.toString());
        } catch (NoSuchAlgorithmException e) {
            System.out.println("MD5 algorithm not found!");
        }

        sc.close();
    }
}