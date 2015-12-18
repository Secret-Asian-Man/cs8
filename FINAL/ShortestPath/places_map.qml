import QtQuick 2.0
import QtPositioning 5.5
import QtLocation 5.5


Rectangle
{
//    id: rect
//    property double latitude: 0
//    property double longitude: 0

//    signal addMarker

//    function setCoord(lat, lon)
//    {
//        latitude = lat;
//        longitude = lon;
//    }



    //property string airport_id: ""




    Plugin
    {
        id: myPlugin
        name: "osm"
    }

    property variant locationLAX: QtPositioning.coordinate(33.94, -118.40)
//    property variant location: QtPositioning.coordinate(latitude, longitude)

    Map
    {
        id: map
        anchors.fill: parent
        plugin: myPlugin;
        center: locationLAX
        zoomLevel: 1



        MapQuickItem
        {
            id: marker
            coordinate: locationLAX
            anchorPoint.x: image.width * 0.1
            anchorPoint.y: image.height
            sourceItem: Column
            {
            Image { id: image; source: "marker.png" }
            Text { text: "LAX"; font.bold: true }
        }
    }
//    Connections
//    {
//        target: rect
//        onAddMarker: setCoord(lat, lon)
//}
}
}


