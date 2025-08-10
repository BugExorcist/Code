package 拓展;

public class MovieFactory {
    public static Movie createRegularMovie(String title) {
        return new Movie(title, new RegularPrice());
    }

    public static Movie createNewReleaseMovie(String title) {
        return new Movie(title, new NewReleasePrice());
    }

    public static Movie createChildrenMovie(String title) {
        return new Movie(title, new ChildrenPrice());
    }

    public static Movie createDocumentaryMovie(String title) {
        return new Movie(title, new DocumentaryPrice());
    }
}
