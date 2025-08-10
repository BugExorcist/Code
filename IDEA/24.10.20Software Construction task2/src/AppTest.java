import MVC.Model;
import org.junit.jupiter.api.Test;

import java.util.Set;

import static org.junit.jupiter.api.Assertions.assertEquals;
import static org.junit.jupiter.api.Assertions.assertTrue;

public class AppTest {

    @Test
    public void testGenerateAdditionProblems() {
        Model model = new Model();
        Set<String> problems = model.generateAdditionProblems(50);
        assertEquals(50, problems.size());
        for (String problem : problems) {
            assertTrue(problem.matches("\\d+ \\+ \\d+ = \\?"));
            String[] parts = problem.split(" \\+ ");
            int a = Integer.parseInt(parts[0]);
            int b = Integer.parseInt(parts[1].replace(" = ?", ""));
            assertTrue(a + b <= 100);
        }
    }

    @Test
    public void testGenerateSubtractionProblems() {
        Model model = new Model();
        Set<String> problems = model.generateSubtractionProblems(50);
        assertEquals(50, problems.size());
        for (String problem : problems) {
            assertTrue(problem.matches("\\d+ - \\d+ = \\?"));
            String[] parts = problem.split(" - ");
            int a = Integer.parseInt(parts[0]);
            int b = Integer.parseInt(parts[1].replace(" = ?", ""));
            assertTrue(a >= b);
        }
    }

    @Test
    public void testGenerateMixedProblems() {
        Model model = new Model();
        Set<String> problems = model.generateMixedProblems(50);
        assertEquals(50, problems.size());
        for (String problem : problems) {
            assertTrue(problem.matches("\\d+ [+-] \\d+ = \\?"));
        }
    }
}
