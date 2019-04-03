//
//  MapViewController.swift
//  Intro_to_ios
//
//  Created by Volodymyr KUKSA on 6/2/18.
//  Copyright © 2018 Volodymyr KUKSA. All rights reserved.
//

import UIKit
import MapKit
import CoreLocation

class MapViewController: UIViewController, CLLocationManagerDelegate {

    @IBOutlet weak var segmentControl: UISegmentedControl!
    
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
    
    let manager = CLLocationManager()
    var region = MKCoordinateRegion()
    var follow = false
    
    
    func locationManager(_ manager: CLLocationManager, didUpdateLocations locations: [CLLocation]) {
        let location = locations[0]
        
        let span:MKCoordinateSpan = MKCoordinateSpanMake(0.01, 0.01)
        
        let myLocation:CLLocationCoordinate2D = CLLocationCoordinate2DMake(location.coordinate.latitude, location.coordinate.longitude)
        
        region.center = myLocation
        region.span = span
        
        if (follow) {
            map.setRegion(region, animated: true)
        }
        self.map.showsUserLocation = true
    }
    
    @IBOutlet weak var locationButt: UIButton!
    
    @IBAction func locationButton(_ sender: Any) {
        follow = !follow
        if (follow) {
            locationButt.tintColor = UIColor.blue
        } else {
            locationButt.tintColor = UIColor.gray
        }
    }
    
// BUTTON
    
    override func viewDidLoad() {
        super.viewDidLoad()
        map.mapType = .hybrid
        let schoolAnnotation = MKPointAnnotation()
        schoolAnnotation.coordinate = CLLocationCoordinate2D(latitude: 48.8965488, longitude:2.3184608)
        schoolAnnotation.title = "42 school"
        schoolAnnotation.subtitle = "tutu tata toto"
        map.addAnnotation(schoolAnnotation)
        
        var region = MKCoordinateRegion()
        var span = MKCoordinateSpan()
        span.latitudeDelta = 0.005
        let centerCoord = CLLocationCoordinate2D(latitude: 48.8965488, longitude:2.3184608)
        region.center = centerCoord
        region.span = span
        map.setRegion(region, animated: true)
        
        // location
        manager.delegate = self
        manager.desiredAccuracy = kCLLocationAccuracyBest
        manager.requestWhenInUseAuthorization()
        manager.startUpdatingLocation()
    }

    override func didReceiveMemoryWarning() {
        super.didReceiveMemoryWarning()
    }
    
}
