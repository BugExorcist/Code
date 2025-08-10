package MVC;

import java.util.Set;

public class View {

    public void displayProblems(Set<String> problems, String title) {
        System.out.println(title);
        for (String problem : problems) {
            System.out.println(problem);
        }
    }
}
