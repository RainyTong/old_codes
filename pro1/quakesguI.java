
import java.net.URL;
import java.time.LocalDate;
import java.util.ArrayList;
import javafx.application.Application;
import javafx.beans.value.ObservableValue;
import javafx.collections.FXCollections;
import javafx.collections.ObservableList;
import javafx.event.ActionEvent;
import javafx.geometry.Insets;
import javafx.scene.Group;
import javafx.scene.Scene;
import javafx.scene.control.Button;
import javafx.scene.control.ComboBox;
import javafx.scene.control.DatePicker;
import javafx.scene.control.Label;
import javafx.scene.control.RadioButton;
import javafx.scene.control.ScrollPane;
import javafx.scene.control.Tab;
import javafx.scene.control.TabPane;
import javafx.scene.control.TableColumn;
import javafx.scene.control.TableView;
import javafx.scene.control.TextField;
import javafx.scene.control.Toggle;
import javafx.scene.control.ToggleGroup;
import javafx.scene.control.cell.PropertyValueFactory;
import javafx.scene.image.Image;
import javafx.scene.image.ImageView;
import javafx.scene.layout.GridPane;
import javafx.scene.layout.HBox;
import javafx.scene.layout.StackPane;
import javafx.scene.layout.VBox;
import javafx.scene.paint.Color;
import javafx.stage.Stage;





public class quakesguI extends Application{
	private final String cssFile = show.class.getClassLoader().getResource("gui.css").toString();
    public static ObservableList<Earthquakes> quakes = null;
	public static ObservableList<Earthquakes> find = FXCollections.observableArrayList();
	public static String singal="nothing";
	public static String minDate="";
	public static String maxDate ="";
	private final StackPane stpMercator = new StackPane();
	//private ComboBox<String>   region = new ComboBox<String>(); 
	private static ObservableList<String> regions = null;
	private static final String[]  tabLabels = {"Data","Mercator Map","Chart by Magnitude","Chart by Date"};
	public static void main(String[] args) {
		 launch(args);
    }
	public void init() {
		readData dataSource=new readData();
		minDate = dataSource.getMinDate();
	    maxDate = dataSource.getMaxDate();
	    try {
	        quakes = FXCollections.observableArrayList(dataSource.getQuakes());
	        // System.out.println("Quake count " + quakes.size());
	        regions = FXCollections.observableArrayList(new ArrayList<String>(dataSource.getRegions()));
	       
	      } catch (Exception e) {
	        System.err.println("load() error: " + e.getMessage());
	        e.printStackTrace();
	        System.exit(1);
	      }
	}
	private void findresult(TableView<Earthquakes> tv){
    	tv.setItems(find);
    }
    private void populate(TableView<Earthquakes> tv) {
	        tv.setItems(quakes);
	 }
    public void searchingbyregion(String fd,String td,String region,Label count){
    	find.clear();
    	for(int i=0;i<quakes.size();i++){
    		
    	if(region.equals("--- World Wide ---")|| region.equals(quakes.get(i).regionProperty().get())){
    		   if(fd.compareTo(quakes.get(i).UTC_dateProperty().get().substring(0,10).trim()) <= 0
    		    			 &&td.compareTo(quakes.get(i).UTC_dateProperty().get().substring(0,10).trim()) >= 0){
    			   find.add(quakes.get(i));
    		    }
    	   }
      }
    	count.setText(find.size()+" quakes selected");
    }
    public void searching(String fd,String td,String region,String text,Label count){
    	find.clear();
    	try{
    		for(int i=0;i<quakes.size();i++){
        		if(fd.compareTo(quakes.get(i).UTC_dateProperty().get().substring(0,10).trim()) <= 0
        			 &&td.compareTo(quakes.get(i).UTC_dateProperty().get().substring(0,10).trim()) >= 0){
        			if(region.equals("--- World Wide ---")|| region.equals(quakes.get(i).regionProperty().get())){
        				switch(singal){
                        case "latitude":
                     	   if(quakes.get(i).latitudeProperty().get()>=Float.parseFloat(text)){
                     		  find.add(quakes.get(i));
                     	   }
                     	   break;
                        case "longitude":
                           if(quakes.get(i).longitudeProperty().get()>=Float.parseFloat(text)){
                        	   find.add(quakes.get(i));
                       	   }
                     	   break;
                        case "depth":
                          if(quakes.get(i).depthProperty().get()>=Integer.parseInt(text)){
                        	  find.add(quakes.get(i));
                       	   }
                     	   break;
                        case "magnitude":
                          if(quakes.get(i).magnitudeProperty().get()>=Float.parseFloat(text)){
                        	  find.add(quakes.get(i));
                       	   }
                     	   break;
                     
        			}
        		}
        	}
          }
        	count.setText(find.size()+" quakes selected");
    	}catch(Exception e){
    		 System.err.println("input error: " + e.getMessage());
    	}
    	
    }
    
    @Override
    public void start(Stage stage) {
    	 stage.setTitle("Earthquakes");
         Group root = new Group();
         Scene scene = new Scene(root,Color.PINK);
         scene.getStylesheets().add(cssFile);
         
         VBox all = new VBox();
         all.setSpacing(8);
         root.getChildren().add(all);
         
         GridPane grid = new GridPane();
         grid.setPadding(new Insets(10, 10, 10, 10));//grid��λ��
         grid.setVgap(10);//�ֿ��ľ���
         grid.setHgap(230);
         all.getChildren().add(grid);
         //dataPicker
         HBox date=new HBox();
         date.setSpacing(10);
         DatePicker fromDate = new DatePicker();
         fromDate.setValue(LocalDate.parse(minDate));
         Label labelFrom = new Label("From:");
         DatePicker toDate = new DatePicker();
         toDate.setValue(LocalDate.parse(maxDate));
         Label labelTo = new Label("To:");
         date.getChildren().addAll(labelFrom,fromDate,labelTo,toDate);
         GridPane.setConstraints(date, 0, 0); // column 0, row 0
         grid.getChildren().add(date);
      
         //region
         HBox place=new HBox();
         place.setSpacing(10);
         ComboBox<String>   region = new ComboBox<String>();
         region.setItems(regions);
         region.setValue("--- World Wide ---");
         Label labelReg = new Label("Region:");
         place.getChildren().addAll(labelReg,region);
         GridPane.setConstraints(place, 0, 1); // column 0, row 0
         grid.getChildren().add(place);
         
         //textfield
         Image imagesearch = new Image(getClass().getResourceAsStream("earthsearch.jpg"));
         final TextField search = new TextField();
         search.setPromptText("Enter Anything about quakes in the bottom.");
         search.setMinHeight(40);
         search.setPrefSize(500, 20);
         Button buttonsearch = new Button();
         buttonsearch.setGraphic(new ImageView(imagesearch));
         HBox shox=new HBox();
         shox.setSpacing(10);
         shox.getChildren().addAll(search,buttonsearch);
         GridPane.setConstraints(shox, 0, 2);
         grid.getChildren().add(shox);
         
         Label s1 = new Label("Anything ��:");
         final ToggleGroup group = new ToggleGroup();
         RadioButton rb1 = new RadioButton("latitude");
         rb1.setToggleGroup(group);
         rb1.setUserData("latitude");

         RadioButton rb2 = new RadioButton("longitude");
         rb2.setToggleGroup(group);
         rb2.setUserData("longitude");
         
         RadioButton rb3 = new RadioButton("depth");
         rb3.setToggleGroup(group);
         rb3.setUserData("depth");
         
         RadioButton rb4 = new RadioButton("magnitude");
         rb4.setToggleGroup(group);
         rb4.setUserData("magnitude");
         
         HBox searchrb = new HBox();
         searchrb.getChildren().addAll(s1,rb1,rb2,rb3,rb4);
         searchrb.setSpacing(10);
         GridPane.setConstraints(searchrb, 0, 3);
         grid.getChildren().add(searchrb);
         group.selectedToggleProperty().addListener(
                 (ObservableValue<? extends Toggle> ov, Toggle old_toggle, 
                 		Toggle new_toggle) -> {
                     if (group.getSelectedToggle() != null) {
                     	singal=group.getSelectedToggle().getUserData().toString();
                     }
             });
         //counter and photo
         Image heart = new Image(getClass().getResourceAsStream("wish.jpg"));
         Label counter = new Label(quakes.size()+" quakes selected");
         Label m = new Label();
         m.setGraphic(new ImageView(heart));
         GridPane.setConstraints(m, 1, 0,1,3);
         GridPane.setConstraints(counter, 1, 3);
         grid.getChildren().addAll(m,counter);
         
         
         // Create the TableView
         //VBox tvbox = new VBox();
        // GridPane.setConstraints(tvbox, 0, 4,2,1);
      //   grid.getChildren().add(tvbox);
        
         TableView<Earthquakes> tv = new TableView<Earthquakes>();
         tv.setPrefWidth(1000);
         tv.setPrefHeight(400);
         // Add the TableView to the box
         //tvbox.getChildren().add(tv);
         // Create the various columns and add them to tv
         TableColumn<Earthquakes,Integer> c1 = new TableColumn<Earthquakes,Integer>("Id");
         c1.setMaxWidth(60);
         c1.setCellValueFactory(new PropertyValueFactory<Earthquakes,Integer>("id"));
         tv.getColumns().add(c1);
         
         TableColumn<Earthquakes,String> c2 = new TableColumn<Earthquakes,String>("UTC_date");
         c2.setMinWidth(180);
         c2.setCellValueFactory(new PropertyValueFactory<Earthquakes,String>("UTC_date"));
         tv.getColumns().add(c2);
        
         TableColumn<Earthquakes,Float> c3 = new TableColumn<Earthquakes,Float>("Latitude");
         c3.setMinWidth(80);
         c3.setCellValueFactory(new PropertyValueFactory<Earthquakes,Float>("latitude"));
         tv.getColumns().add(c3);
         
         TableColumn<Earthquakes,Float> c4 = new TableColumn<Earthquakes,Float>("Longitude");
         c4.setMinWidth(95);
         c4.setCellValueFactory(new PropertyValueFactory<Earthquakes,Float>("longitude"));
         tv.getColumns().add(c4);
           
         TableColumn<Earthquakes,Integer> c5 = new TableColumn<Earthquakes,Integer>("Depth");
         c5.setMaxWidth(70);
         c5.setCellValueFactory(new PropertyValueFactory<Earthquakes,Integer>("depth"));
         tv.getColumns().add(c5);
            
         TableColumn<Earthquakes,Float> c6 = new TableColumn<Earthquakes,Float>("Magnitude");
         c6.setMinWidth(100);
         c6.setCellValueFactory(new PropertyValueFactory<Earthquakes,Float>("magnitude"));
         tv.getColumns().add(c6);
             
         TableColumn<Earthquakes,String> c7 = new TableColumn<Earthquakes,String>("Region");
         c7.setMinWidth(340);
         c7.setCellValueFactory(new PropertyValueFactory<Earthquakes,String>("region"));
         tv.getColumns().add(c7);
         //tabpane
         TabPane pane = new TabPane();
         all.getChildren().add(pane);
         Tab      tab;
         VBox     tabBox;
         URL      url;
         Image     image;
         ImageView mercator;
         for (int i = 0; i < tabLabels.length; i++) {
             tab = new Tab();
             tabBox = new VBox();
             tabBox.setPadding(new Insets(20));
             switch(i){
             case 0:
                 ScrollPane scrPane = new ScrollPane();
                 tabBox.getChildren().add(scrPane);
                 scrPane.setContent(tv);
                 break;
             case 1:
            	 tabBox.getChildren().add(stpMercator);
            	 Image map = new Image(getClass().getResourceAsStream("Mercator.jpg"));
            	 mercator = new ImageView(map);
            	 stpMercator.getChildren().add(mercator);
             }
             tab.setText(tabLabels[i]);
             tab.setClosable(false);
             tab.setContent(tabBox);
             pane.getTabs().add(tab);
         }
         //searching
         buttonsearch.setOnAction((ActionEvent e) -> {
        	 if(singal.equals("nothing")){
        		 searchingbyregion(fromDate.getValue().toString(),toDate.getValue().toString(),region.getValue(),counter);
        	 }
        	 else if ((search.getText() != null && !search.getText().isEmpty())) {
        		 searching(fromDate.getValue().toString(),toDate.getValue().toString(),
          			   region.getValue(),search.getText(),counter);
        	 }else{
        		 searchingbyregion(fromDate.getValue().toString(),toDate.getValue().toString(),region.getValue(),counter);
        		 
        	 }
        	
        	 findresult(tv);
         });
         populate(tv);
         stage.setScene(scene);
         stage.show();
        
    }
}
