/******************************************************************************
Solution for https://www.beecrowd.com.br/judge/en/problems/view/1052

*******************************************************************************/
import java.util.Scanner;
import java.util.HashMap;
import java.util.Map;

public class Main
{
	public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        Map<Integer, String> calendar = Map.ofEntries(
            Map.entry(1, "January"),
            Map.entry(2, "February"),
            Map.entry(3, "March"),
            Map.entry(4, "April"),
            Map.entry(5, "May"),
            Map.entry(6, "June"),
            Map.entry(7, "July"),
            Map.entry(8, "August"),
            Map.entry(9, "September"),
            Map.entry(10, "October"),
            Map.entry(11, "November"),
            Map.entry(12, "December")
        );
        int choice = scanner.nextInt();
        String month = new String(calendar.get(choice));
        System.out.println(month);
	}
}

