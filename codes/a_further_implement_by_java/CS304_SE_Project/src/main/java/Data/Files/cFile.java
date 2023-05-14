package Data.Files;
import java.io.File;
public abstract class cFile {
    private File file;

    public File getFile() {
        return file;
    }

    public void setFile(File file) {
        this.file = file;
    }
}
