
import java.io.File;
import java.io.FileFilter;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.UnsupportedEncodingException;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.Properties;
import java.util.Set;

public class LanguageGuesser {

	public static void main(String[] args)  {

		Properties props = new Properties();

		FileInputStream input;
		try {

			input = new FileInputStream("language.cnf");
			try {
				props.load(input);
			} catch (IOException e) {
				e.printStackTrace();
			}

			String pathOfStops = props.getProperty("stop_words_dir");//get the path of resources
			List<Map> allMaps = new ArrayList<Map>();
			List<String> listOfFiles = new ArrayList<String>();
			try{
	        listOfFiles = getFileList(pathOfStops);
			}catch (FileNotFoundException e) {
				System.out.println("Sorry, the directory isn't found. Please check the file's name and whether it exists(may be spelling mistake or renaming mistake).");
				e.printStackTrace();
			}
	        allMaps = buildMap(allMaps,listOfFiles);

	        String language = findLan(args[0],allMaps,listOfFiles);

	        language = nameHandler(language);
			System.out.println(language);

		} catch (FileNotFoundException e1) {
			System.out.println("Sorry, the expected .cnf file isn't found.");

			e1.printStackTrace();
		}

	}

	public static String findLan (String path,List<Map> mapList,List<String> fileList){
		Tokenizer tokenizer = null;
		try {
			tokenizer = new Tokenizer(path);
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		String str = tokenizer.nextToken();
		while(str != null) {
			for(int i = 0; i < mapList.size();i++){
				if(mapList.get(i).containsKey(str)){
					int value = (int) (mapList.get(i).get(str)) + 1;
					mapList.get(i).put(str,value);
				}
			}
			str = tokenizer.nextToken();
		}
		int max = 0;
		String lan = "";
		for(int i = 0;i<mapList.size();i++) {
			int count = 0;
			Map<String,Integer> map = mapList.get(i);
			for(String string:map.keySet()){
				if(map.get(string)>0){
					count++;
				}
			}
			if(count>max){
				max = count;
				lan = fileList.get(i);
			}
		}
		return lan;
	}

	public static List<Map> buildMap(List<Map> mapList,List<String> fileList) {
		for(int i = 0;i<fileList.size();i++) {
			Map<String,Integer> map = new HashMap<String,Integer>();
			Tokenizer tokenizer = null;
			try {
				tokenizer = new Tokenizer(fileList.get(i));
			} catch (FileNotFoundException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			} catch (UnsupportedEncodingException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			} catch (IOException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
			String str = tokenizer.nextToken();
			while(str != null){
				map.put(str,0);
				str = tokenizer.nextToken();
			}
			mapList.add(map);
		}
		return mapList;
	}

	public static List<String> getFileList(String FILE_IN) throws FileNotFoundException{

		File file = new File(FILE_IN);
		List<String> result = new ArrayList<String>();

		try{
        if (!file.isDirectory()) {
            System.out.println(file.getAbsolutePath());
            result.add(file.getAbsolutePath());
        } else {
            File[] directoryList = file.listFiles(new FileFilter() {
                public boolean accept(File file) {
                    if (file.isFile() && file.getName().indexOf("txt") > -1) {
                        return true;
                    } else {
                        return false;
                    }
                }
            });
            if(directoryList.length == 0){
            	throw new Exception();
            }
            for (int i = 0; i < directoryList.length; i++) {
                result.add(directoryList[i].getPath());
            }
        }
	}catch(Exception e){
		System.out.println("Sorry, there is no .txt file.");
	}

        return result;
	}

	public static String nameHandler(String pathName){
		StringBuilder name = new StringBuilder(pathName);
		String invName = name.reverse().toString();
		StringBuilder invnewName = new StringBuilder();
		int index = 4;
		while(invName.charAt(index) != '/'){
			invnewName.append(invName.charAt(index));
			index++;
		}
		String newName = invnewName.reverse().toString();
		return newName;
	}
}
