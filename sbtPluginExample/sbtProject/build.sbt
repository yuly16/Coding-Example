import sbt.Keys._
lazy val root = (project in file(".")).
  settings(
    scalaVersion := "2.13.8",
    name := "sbtProject"
  ).
  enablePlugins(MySBTPlugin)