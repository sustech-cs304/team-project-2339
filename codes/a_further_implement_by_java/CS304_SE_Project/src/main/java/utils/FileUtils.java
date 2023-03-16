package utils;

import Data.DataStore;
import Data.Files.cFile;

public class FileUtils {
    public static boolean checkFileType(DataStore store, Class<? extends cFile> fileClass){
        try{
            return store.file.getClass().equals(fileClass);
        }catch (NullPointerException e){
            return false;
        }
    }
}
