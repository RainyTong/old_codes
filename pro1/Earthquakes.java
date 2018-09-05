package read;

import javafx.beans.property.SimpleFloatProperty;
import javafx.beans.property.SimpleIntegerProperty;
import javafx.beans.property.SimpleStringProperty;

public class Earthquakes {
	private SimpleIntegerProperty id;
	private SimpleStringProperty UTC_date;
    private SimpleFloatProperty  latitude;
    private SimpleFloatProperty  longitude;
    private SimpleIntegerProperty depth;
    private SimpleFloatProperty magnitude;
    private SimpleStringProperty region;
    
    public Earthquakes(int id, String UTC_date,float  latitude, float  longitude,int depth,float magnitude,String region) {
    this.id = new SimpleIntegerProperty(id);
    this.UTC_date = new SimpleStringProperty(UTC_date);
    this.latitude = new SimpleFloatProperty(latitude);
    this.longitude = new SimpleFloatProperty(longitude);
    this.depth = new SimpleIntegerProperty(depth);
    this.magnitude = new SimpleFloatProperty(magnitude);
    this.region = new SimpleStringProperty(region);
}
    
    public SimpleIntegerProperty idProperty() {
        return id;
    }
    
    public SimpleStringProperty UTC_dateProperty() {
        return UTC_date;
    }
    
    public SimpleFloatProperty latitudeProperty() {
        return latitude;
    }
    
    public SimpleFloatProperty longitudeProperty() {
        return longitude;
    }
    
    public SimpleIntegerProperty depthProperty() {
        return depth;
    }
    
    public SimpleFloatProperty magnitudeProperty() {
        return magnitude;
    }
    
    public SimpleStringProperty regionProperty() {
        return region;
    }

   

   


}
