import java.net.URL;
import java.util.Random;
import java.util.ResourceBundle;
import javafx.application.Application;
import javafx.event.ActionEvent;
import javafx.event.EventHandler;
import javafx.fxml.FXMLLoader;
import javafx.fxml.Initializable;
import javafx.geometry.Insets;
import javafx.geometry.Pos;
import javafx.geometry.Rectangle2D;
import javafx.stage.Screen;
import javafx.stage.Stage;
import javafx.scene.Node;
import javafx.scene.Parent;
import javafx.scene.Scene;
import javafx.scene.control.Button;
import javafx.scene.input.MouseEvent;
import javafx.scene.layout.BorderPane;
import javafx.scene.layout.GridPane;
import javafx.scene.layout.StackPane;


public class Main extends Application implements Initializable{

@Override
public void start(Stage primaryStage) {

  try{
    Parent root = FXMLLoader.load(getClass().getResource("mainUI.fxml"));
    primaryStage.setTitle("My Application");
    primaryStage.setScene(new Scene(root));
    primaryStage.show();
  } catch (Exception e){
    e.printStackTrace();
  }

}

public static void main(String[] args) {
  launch(args);
}



private Rectangle2D screenBounds
        = Screen.getPrimary().getVisualBounds();
private Random rand_generator;
private double x;
private double y;

@Override
public void initialize(URL location, ResourceBundle resources){
  rand_generator = new Random();
}
public void moveWindow(MouseEvent me){
  Node node = (Node)me.getSource();
  Stage stage = (Stage) node.getScene().getWindow();
  double height = screenBounds.getHeight();
  double width = screenBounds.getWidth();

  double x_move = width/10 + rand_generator.nextDouble()*width/2;
  double y_move = height/10 + rand_generator.nextDouble()*height/2;

  this.x = (double) ((long)(this.x+x_move)%(long)(width-stage.getWidth()));
  this.y = (double) ((long)(this.y+y_move)%(long)(height-stage.getHeight()));

  stage.setX(this.x);;
  stage.setY(this.y);


}



}
