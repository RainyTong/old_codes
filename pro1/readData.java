package read;

import java.io.BufferedReader;
import java.io.FileReader;
import java.util.ArrayList;
import java.util.TreeSet;





public class readData {
	private final ArrayList<Earthquakes> Quakes = new ArrayList<Earthquakes>();
	private final TreeSet<String>  regionSet = new TreeSet<String>();
	private String minDate = "9999-99-99";
	private String maxDate = "0000-00-00";
	
	private void readQuakes(){
		 String    thisDate;
		 String    thisDay;
		 String    thisRegion;
		 
		 regionSet.add("--- World Wide ---");
		   try (BufferedReader reader =
		            new BufferedReader(new FileReader("earthquakes.csv"))) {
		       String     line = null;
		       String[]   fields;
		       int counter = 0;
		       while ((line = reader.readLine()) != null) {
		    	   if(counter==0){
	        		   counter++;
	        		   continue;
	        	   }
		           if (line.length() > 0) {
		             fields = line.split(",");
		             thisDate = fields[1].replace("\"", "").substring(0,19);
		             thisDay = thisDate.substring(0, 10).trim();
		             thisRegion = fields[6].replace("\"", "").trim();
		             regionSet.add(thisRegion);
		             Quakes.add(new Earthquakes(Integer.parseInt(fields[0]),
		                                       thisDate, 
		                                       Float.parseFloat(fields[2]),
		                                       Float.parseFloat(fields[3]),
		                                       Integer.parseInt(fields[4]),
		                                       Float.parseFloat(fields[5]),
		                                       thisRegion));
		             if (thisDay.compareTo(minDate) < 0) {
		               minDate = thisDay;
		             } else if (thisDay.compareTo(maxDate) > 0) {
		               maxDate = thisDay;
		             }
		           }
		         }
		      
		       
		    } catch (Exception e) {
		       System.err.println("Error: " + e.getMessage());
		       e.printStackTrace();
		    }
	}
	public readData() {
	   readQuakes();
	}
	public String getMinDate() {
	    return minDate;
	}

	public String getMaxDate() {
	    return maxDate;
	}
	
	public TreeSet<String> getRegions() {
	    return regionSet;
	}
	public ArrayList<Earthquakes> getQuakes(){
		return Quakes;
	}
}
