import java.io.*;
import java.util.Arrays;

public class Main {
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int[] time = Arrays.stream(br.readLine().split(" "))
                    .mapToInt(Integer::parseInt)
                    .toArray();
        int plusTime = Integer.parseInt(br.readLine());

        time[1] += plusTime;

        if (time[1] > 59) {
            time[0] += time[1] / 60;
            time[1] %= 60;
            time[0] %= 24;
        }

        System.out.print(time[0] + " " + time[1]);
    }
}
