//
//  BarMap.swift
//  Intro_to_ios
//
//  Created by Volodymyr KUKSA on 6/3/18.
//  Copyright © 2018 Volodymyr KUKSA. All rights reserved.
//

import UIKit
import MapKit
import CoreLocation

class BarMap: UIViewController, CLLocationManagerDelegate {

    @IBOutlet weak var segmentControl: UISegmentedControl!
    
    @IBOutlet weak var navTitle: UINavigationItem!
    
    @IBOutlet weak var map: MKMapView!
    
    @IBAction func indexChanged(_ sender: Any) {
        switch segmentControl.selectedSegmentIndex
        {
        case 0:
            map.mapType = .standard
        case 1:
            map.mapType = .satellite
        case 2:
            map.mapType = .hybrid
        default:
            map.mapType = .standard
        }
    }
    
    struct Location {
        let title: String
        let subtitle: String
        let longitude: Double
        let latitude: Double
    }
    
    var index: Int? = nil
    
    var annotations = [
        Location(title: "Bar 1", subtitle: "Barttt 1", longitude: 40.0, latitude: 30.0),
        Location(title: "Bar 2", subtitle: "Bar 2ttt", longitude: 50.0, latitude: 20.0),
        Location(title: "42 school", subtitle: "tutu tata toto", longitude: 2.3184608, latitude: 48.8965488),
        Location(title: "UNIT Factory", subtitle: "Частная школа", longitude: 30.462100, latitude: 50.468962)
    ]
    
    let manager = CLLocationManager()
    var region = MKCoordinateRegion()
    var follow = false
    
    // LOCATION
    @IBOutlet weak var locationButt: UIButton!
    
    func locationManager(_ manager: CLLocationManager, didUpdateLocations locations: [CLLocation]) {
        let location = locations[0]
        
        let span:MKCoordinateSpan = MKCoordinateSpanMake(0.01, 0.01)
        
        let myLocation:CLLocationCoordinate2D = CLLocationCoordinate2DMake(location.coordinate.latitude, location.coordinate.longitude)
        
        region.center = myLocation
        region.span = span
        
        if (follow) {
            locationButt.tintColor = UIColor.blue
            map.setRegion(region, animated: true)
        } else {
            locationButt.tintColor = UIColor.gray
        }
        
        self.map.showsUserLocation = true
    }
    
    @IBAction func locationButton(_ sender: Any) {
        follow = !follow
    }
    

    
    
    override func viewDidLoad() {
        super.viewDidLoad()
        map.mapType = .hybrid
        if let nameIndex = index {
            let currentAnnotation = MKPointAnnotation()
            currentAnnotation.coordinate.latitude = annotations[nameIndex].latitude
            currentAnnotation.coordinate.longitude = annotations[nameIndex].longitude
            currentAnnotation.title = annotations[nameIndex].title
            currentAnnotation.subtitle = annotations[nameIndex].subtitle
            map.addAnnotation(currentAnnotation)
            
            navTitle.title = currentAnnotation.title
        
            navTitle.title = annotations[nameIndex].title
        
            var region = MKCoordinateRegion()
            var span = MKCoordinateSpan()
            span.latitudeDelta = 0.005
            region.center = currentAnnotation.coordinate
            region.span = span
            map.setRegion(region, animated: true)
            
        }
        
        // location
        manager.delegate = self
        manager.desiredAccuracy = kCLLocationAccuracyBest
        manager.requestWhenInUseAuthorization()
        manager.startUpdatingLocation()
    }
    
    override func didReceiveMemoryWarning() {
        super.didReceiveMemoryWarning()
    }
    
    
    /*
     // MARK: - Navigation
     
     // In a storyboard-based application, you will often want to do a little preparation before navigation
     override func prepare(for segue: UIStoryboardSegue, sender: Any?) {
     // Get the new view controller using segue.destinationViewController.
     // Pass the selected object to the new view controller.
     }
     */

}
